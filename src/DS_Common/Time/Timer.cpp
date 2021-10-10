// Timer.cpp

/* Header */
//====================================================================================================
#include <chrono>
#include <sstream>
#include <ctime>   // localtime
#include <iomanip> // put_time
#include <thread>
#include <mutex>

#include <DS_Common/Time/Timer.h>
//#include <DS_Common/Type/TypeConversion.h>
//====================================================================================================




/* Private Mmeber */
//====================================================================================================

namespace DS_Common {
	namespace Time {
		class Timer::Member
		{
		public: // Variable
			std::chrono::system_clock::time_point time_start;
		public: // Function
			Member();
		};
	}
}
//====================================================================================================



/* Public Function */
//====================================================================================================

namespace DS_Common {
	namespace Time
	{
		//------------------------------------------------------------------------------------------------
		Timer::Timer() :member(new Timer::Member())
		{

		}

		//------------------------------------------------------------------------------------------------

		Timer::~Timer()
		{

		}

		//------------------------------------------------------------------------------------------------

		void Timer::start()
		{
			member->time_start = std::chrono::system_clock::now();
		}

		//------------------------------------------------------------------------------------------------

		double Timer::getSec()
		{
			return 0.001*this->getMSec();
		}

		//------------------------------------------------------------------------------------------------
		double Timer::getMSec()
		{
			return std::chrono::duration_cast<std::chrono::milliseconds>(
				std::chrono::system_clock::now() - member->time_start).count();
		}

        //------------------------------------------------------------------------------------------------
        double Timer::getMicroSec()
        {
            return std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::system_clock::now() - member->time_start).count();
        }

		//------------------------------------------------------------------------------------------------
	    /*std::string Timer::getTime(std::string setting)
		{

            time_t now = time(0);
            tm *ltm = localtime(&now);

            std::string dateString = "", tmp = "";
            tmp = Common::Type::to_string(ltm->tm_mday);
            if (tmp.length() == 1)
                tmp.insert(0, "0");
            dateString += tmp;
            dateString += "_";
            tmp = Common::Type::to_string(1 + ltm->tm_mon);
            if (tmp.length() == 1)
                tmp.insert(0, "0");
            dateString += tmp;
            dateString += "_";
            tmp = Common::Type::to_string(1900 + ltm->tm_year);
            dateString += tmp;
            dateString += "_";
            tmp = Common::Type::to_string(ltm->tm_hour);
            if (tmp.length() == 1)
                tmp.insert(0, "0");
            dateString += tmp;
            dateString += "_";
            tmp = Common::Type::to_string(1 + ltm->tm_min);
            if (tmp.length() == 1)
                tmp.insert(0, "0");
            dateString += tmp;
            dateString += "_";
            tmp = Common::Type::to_string(1 + ltm->tm_sec);
            if (tmp.length() == 1)
                tmp.insert(0, "0");
            dateString += tmp;

            return dateString;
		}*/
	}
}
//====================================================================================================



/* Private Function */
//====================================================================================================

namespace DS_Common {
	namespace Time
	{
		//------------------------------------------------------------------------------------------------
		Timer::Member::Member()
		{
			this->time_start = std::chrono::system_clock::now();
		}
		//------------------------------------------------------------------------------------------------
	}
}
//====================================================================================================