// TestTime.cpp

/* Header */
//====================================================================================================
#include <iostream>
#include <string>

#include <DS_Common/Test/UnitTest.h>

#include <DS_Common/Time/Timer.h>

#include <DS_Common/Sort/HeapSort.h>
#include <DS_Common/Sort/InsertionSort.h>
#include <DS_Common/Sort/MergeSort.h>
#include <DS_Common/Sort/QuickSort.h>
//====================================================================================================


/* Definition */
//====================================================================================================
namespace UnitTest {
	class TestSort :public UnitTest::Test {
	protected:
        std::string MODULE_NAME = "Sort";
		DS_Common::Time::Timer *timer;

		int *seq;
		int seq_size;


	protected:  //function
		//--------------------------------------------------------------------------------------------
		virtual void SetUp()
		{
			timer = new DS_Common::Time::Timer();
			seq = NULL;
		}

		//--------------------------------------------------------------------------------------------
		virtual void TearDown()
		{
			timer->~Timer();
		}

		//--------------------------------------------------------------------------------------------
		bool isSorted(int *seq, int n)
		{
			for (int i = 0; i < n - 1; i++)
			{
				if (seq[i] > seq[i + 1])
				{
					/*for (int j = 0; j < n; j++)
						std::cout << seq[j] << "," << std::endl;*/
					return false;
				}
					
			}
			return true;
		};
		//--------------------------------------------------------------------------------------------
		void initialize(const int n)
		{
			srand(time(NULL));

			if (!seq)
			{
				free(seq);
				seq = NULL;
			}

			seq = (int*)malloc(n * sizeof(int));
			seq_size = n;

			for (int i = 0; i < n; i++)
			{
				seq[i] = rand();
			}
		};
		//--------------------------------------------------------------------------------------------
	};
}
//====================================================================================================


/* Function */
//====================================================================================================
namespace UnitTest {

	//------------------------------------------------------------------------------------------------
	TEST_F(TestSort, testQuickSort) {

		std::vector<int> test_size = {5, 50, 100,1000,10000};

		std::vector<int> repeated_loop = { 10000, 10000,10000,1000,100};
		
		int number_methods = 2;
		std::vector<double> elapsed_time(number_methods, 0);


		for (int j = 0; j < test_size.size();j++) // size
		{
			for (int i = 0; i < repeated_loop[j]; i++)
			{
				initialize(test_size[j]);			// initialize

				// Insertion Sort
				timer->start();
				DS_Common::InsertionSort(seq, seq_size);
				elapsed_time[0] += timer->getMicroSec();
				EXPECT_TRUE(isSorted(seq, seq_size));

				// Quick Sort
				timer->start();
				DS_Common::QuickSort(seq, 0, seq_size-1);
				elapsed_time[1] += timer->getMicroSec();
				EXPECT_TRUE(isSorted(seq, seq_size));
			}

			std::cout << "Size: " << test_size[j] << std::endl;
			for (int k = 0; k < number_methods; k++)
			{
				elapsed_time[k] /= repeated_loop[k];

				std::cout << "elapsed_time of " << k << " : " << elapsed_time[k] << std::endl;;
			}
			std::cout << std::endl;
		}	
	}

	//------------------------------------------------------------------------------------------------

	TEST_F(TestSort, Timer_start) {
		
		//std::cout << "initial timer is (ms) " << timer->getMSec() <<
		//	", (sec) " << timer->getSec() << std::endl;

		//// just elapse time.
		//system("pause");

		//std::cout << "current timer is (ms) " << timer->getMSec() <<
		//	", (sec) " << timer->getSec() << std::endl;
		//timer->start();
		//std::cout << "current timer after start() is (ms) " << timer->getMSec() <<
		//	", (sec) " << timer->getSec() << std::endl;
	}

	//------------------------------------------------------------------------------------------------
}
//====================================================================================================