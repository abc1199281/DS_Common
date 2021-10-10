// TestPriorityQueue.cpp

/* Header */
//====================================================================================================
#include <iostream>
#include <string>

#include <DS_Common/Test/UnitTest.h>

#include <DS_Common/Queue/PriorityQueue.h>
//====================================================================================================


/* Definition */
//====================================================================================================
namespace UnitTest {
	class TestPriorityQueue :public UnitTest::Test {
	protected:
        std::string MODULE_NAME = "PriorityQueue";
		
		virtual void SetUp()
		{
			
		}

		virtual void TearDown()
		{
			
		}
	};
}
//====================================================================================================


/* Function */
//====================================================================================================
namespace UnitTest {

	//------------------------------------------------------------------------------------------------
	TEST_F(TestPriorityQueue, BasicTest) {

		
		for (int j = 0; j < 100; j++) {
			int N = 100;

			DS_Common::PriorityQueue<int> q;
			for (int i = 0; i < N; i++)
			{
				q.push(rand() - 1);
			}

			int previous = INT_MAX;
			while (!q.isempty())
			{
				EXPECT_TRUE(previous >= q.top());
				previous = q.top();
				q.pop();
			}
		}
		
	}
	//------------------------------------------------------------------------------------------------
}
//====================================================================================================