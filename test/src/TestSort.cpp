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
					for (int j = 0; j < n; j++)
						std::cout << seq[j] << "," << std::endl;
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
		int* copySeq()
		{
			int *copySeq = (int*)malloc(seq_size *sizeof(int));

			for (int i = 0; i < seq_size; i++)
				copySeq[i] = seq[i];
			return copySeq;
		}
		//--------------------------------------------------------------------------------------------
	};
}
//====================================================================================================


/* Function */
//====================================================================================================
namespace UnitTest {

	//------------------------------------------------------------------------------------------------
	TEST_F(TestSort, TestAvgCase) {

		std::vector<int> test_size = {5, 50, 100,1000,10000};
		std::vector<int> repeated_loop = { 10000, 10000,10000,1000 ,100};

		//std::vector<int> test_size = { 10 };
		//std::vector<int> repeated_loop = { 10000};
		
		int number_methods = 4;
		std::vector<double> elapsed_time(number_methods, 0);


		for (int j = 0; j < test_size.size();j++) // size
		{
			for (int i = 0; i < repeated_loop[j]; i++)
			{
				initialize(test_size[j]);			// initialize
				int *test_seq;

				// Quick Sort
				test_seq = copySeq(); timer->start();
				DS_Common::QuickSort(test_seq, 0, seq_size - 1); // sort
				elapsed_time[0] += timer->getMicroSec();
				EXPECT_TRUE(isSorted(test_seq, seq_size));
				free(test_seq); test_seq = NULL;

				//// Recursive Merge Sort (not very well defined.)
				//int *link = (int*)calloc(seq_size+1, sizeof(int));
				//for (int i = 0; i < seq_size+1; i++)
				//	link[i] = -1;
				//test_seq = copySeq(); timer->start();
				//DS_Common::rMergeSort(test_seq,link, 0,seq_size-1); // sort
				//elapsed_time[1] += timer->getMicroSec();
				////EXPECT_TRUE(isSorted(test_seq, seq_size));
				//free(test_seq); test_seq = NULL;
				//free(link); link = NULL;

				 //Recursive Merge Sort (with copy)				
				test_seq = copySeq(); timer->start();
				DS_Common::rMergeSort_copy(test_seq,0, seq_size - 1); // sort
				elapsed_time[1] += timer->getMicroSec();
				EXPECT_TRUE(isSorted(test_seq, seq_size));
				free(test_seq); test_seq = NULL;	

				// HeapSort (std::priority_queue is roughly quick sort)
				test_seq = copySeq();
				timer->start();
				DS_Common::HeapSort(test_seq, seq_size); // sort
				elapsed_time[2] += timer->getMicroSec();
				EXPECT_TRUE(isSorted(test_seq, seq_size));
				free(test_seq); test_seq = NULL;

				// Insertion Sort
				test_seq = copySeq();
				timer->start();
				DS_Common::InsertionSort(test_seq, seq_size); // sort
				elapsed_time[3] += timer->getMicroSec();
				EXPECT_TRUE(isSorted(test_seq, seq_size));
				free(test_seq); test_seq = NULL;
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