// TestTime.cpp

/* Header */
//====================================================================================================
#include <iostream>
#include <string>

#include <DS_Common/Test/UnitTest.h>

#include <DS_Common/Time/Timer.h>
//====================================================================================================


/* Definition */
//====================================================================================================
namespace UnitTest {
	class TestGraph :public UnitTest::Test {
	protected:
        std::string MODULE_NAME = "Time";
		DS_Common::Time::Timer *timer;
		virtual void SetUp()
		{
			timer = new DS_Common::Time::Timer();
		}

		virtual void TearDown()
		{
			timer->~Timer();
		}
	};
}
//====================================================================================================


/* Function */
//====================================================================================================
namespace UnitTest {

	//------------------------------------------------------------------------------------------------
	TEST_F(TestGraph, Timer_getSec) {
		std::cout <<"initial timer is (ms) " << timer->getMSec() <<
					", (sec) "<< timer->getSec() << std::endl;
		
		// just elapse time.
		system("pause");

		std::cout << "current timer is (ms) " << timer->getMSec() <<
					 ", (sec) " << timer->getSec() << std::endl;
	}

	//------------------------------------------------------------------------------------------------

	TEST_F(TestGraph, Timer_start) {
		
		std::cout << "initial timer is (ms) " << timer->getMSec() <<
			", (sec) " << timer->getSec() << std::endl;

		// just elapse time.
		system("pause");

		std::cout << "current timer is (ms) " << timer->getMSec() <<
			", (sec) " << timer->getSec() << std::endl;
		timer->start();
		std::cout << "current timer after start() is (ms) " << timer->getMSec() <<
			", (sec) " << timer->getSec() << std::endl;
	}

	//------------------------------------------------------------------------------------------------

}
//====================================================================================================