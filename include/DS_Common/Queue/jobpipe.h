
#pragma once
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>

template<typename T>
class jobPipe
{
public:

    using FrameReceiveCallback = std::function< int(T &req) >;

    jobPipe(int qSz = 10) :stop_(false), maxSize_(qSz) {}

    ~jobPipe() {
        stop();
        if (thr_ && thr_->joinable())
            thr_->join();
    }

    int push(T data, bool to_skip_first = false)
    {
        std::unique_lock<std::mutex> lock(mutex_);
        if (to_skip_first && (int)cpq_.size() >= maxSize_)
        {
            cpq_.pop();
        }

        if ((int)cpq_.size() < maxSize_)
        {
            cpq_.push(std::move(data));
            lock.unlock();
            cond_.notify_all();
            return 0;
        }

        return -1;
    }
    void start()
    {
        thr_ = std::make_shared<std::thread>(std::bind(&jobPipe::consumeThr, this));
    }

    void set_callback(FrameReceiveCallback  fun) {
        frm_callback_ = fun;
    }

    void stop()
    {
        stop_ = true;
        cond_.notify_all();
    }

    bool hasDataInQueue(void)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        bool ret = !this->cpq_.empty();
        return ret;
    }

private:

    void consumeThr()
    {
        while (!stop_)
        {
            std::unique_lock<std::mutex> lock(mutex_);
            if (cpq_.size() == 0)
                cond_.wait(lock);
            if (cpq_.size() > 0)
            {
                T req = std::move(cpq_.front());
                cpq_.pop();
                lock.unlock();
                if (frm_callback_)
                    frm_callback_(req);
            }
        }
        //std::cout << "Finish" << std::endl;
    }

    bool stop_;
    std::condition_variable cond_;
    std::mutex mutex_;
    std::queue<T> cpq_;
    std::shared_ptr<std::thread> thr_;
    int maxSize_;

    FrameReceiveCallback frm_callback_;
};
