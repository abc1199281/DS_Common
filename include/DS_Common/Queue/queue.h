// Queue.h

#ifndef __DS_COMMON_QUEUE_H__
#define __DS_COMMON_QUEUE_H__

/* Information */
//====================================================================================================

/*!
*  @file   queue.h
*
*  @brief  queue.
*
*  @author Po-Wei Huang
*
*  @date   2021/05/22
*/

//====================================================================================================


/* Header */
//====================================================================================================

#include <iostream>
#include <vector>
#include <condition_variable>
#include <algorithm>

#include <DS_Common/Common/Common.h>
#include <DS_Common/LibSetting/LibSetting.h>
//====================================================================================================


/* Definition */
//====================================================================================================
//====================================================================================================

/* Class */
//====================================================================================================

namespace DS_Common {
	template<typename T>
	class  DS_COMMON_EXPORTS queue
	{
	private: // variable
		T* queue_array;
		int front_idx;
		int back_idx;
		int capacity;

	public: // function

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Constructor
		*
		*/
		queue(int n = 10);
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Access next element 
		*
		*/
		T& front() const;
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Access last element
		*
		*/
		T& back() const;
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      pop
		*
		*/
		void pop();
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      push
		*/
		void push(const T& e);
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Default Constructor
		*
		*/
		bool empty() const { return front_idx == back_idx; };
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Destructor
		*
		*/
		~queue() {}
		//-----------------------------------------------------------------------------------------

	};
	//--------------------------------------------------------------------------------------------
}
//====================================================================================================


/* Public Function */
//====================================================================================================

namespace DS_Common {
	//------------------------------------------------------------------------------------------------
	template<typename T>
	queue<T>::queue(int n) : capacity(n)
	{
		if (n < 1) throw "Capacity of stack must be >=1.";
		queue_array = new T[n];
		front_idx = back_idx = 0;
	}
	//------------------------------------------------------------------------------------------------

	template<typename T>
	void queue<T>::push(const T& x) {
		if ((back_idx+1)%capacity == front_idx)
		{
			T* newQueue = new T[2 * capacity];
			int start = (front_idx + 1) % capacity;
			if (start < 2)
				std::copy(queue_array +start, queue_array+start+capacity-1, newQueue);
			else {
				std::copy(queue_array + start, queue_array+capacity, newQueue);
				std::copy(queue_array, queue_array + back_idx +1, newQueue+capacity-start);
			}
			front_idx = 2 * capacity - 1;
			back_idx = capacity - 2;
			capacity *= 2;
			delete[] queue_array;
			queue_array = newQueue;

		}
		back_idx = (back_idx + 1) % capacity;
		queue_array[back_idx] = x;
	}
	//------------------------------------------------------------------------------------------------

	template<typename T>
	void queue<T>::pop() {
		if (empty()) throw "Queue is empty, cannot delete.";
		front_idx = (front_idx + 1) % capacity;
		//queue_array[front_idx].~T();
	}
	//------------------------------------------------------------------------------------------------

	template<typename T>
	T&  queue<T>::front() const {
		if (empty()) 
			throw "Queue is empty";
		return queue_array[(front_idx+1)%capacity];
	}
	//------------------------------------------------------------------------------------------------

	template<typename T>
	T&  queue<T>::back() const {
		if (empty()) throw "Queue is empty";
		return queue_array[back_idx];
	}
	//------------------------------------------------------------------------------------------------
}
//====================================================================================================
#endif /* __DS_COMMON_QUEUE_H__ */