// PriorityQueue.h

#ifndef __DS_COMMON_PRIORITY_QUEUE_H__
#define __DS_COMMON_PRIORITY_QUEUE_H__

/* Information */
//====================================================================================================

/*!
*  @file   PriorityQueue.h
*
*  @brief  PriorityQueue implementation usin BinaryTree.
*
*  @author Po-Wei Huang
*
*  @date   2021/04/24
*/

//====================================================================================================


/* Header */
//====================================================================================================

#include <iostream>
#include <vector>
#include <condition_variable>

#include <DS_Common/LibSetting/LibSetting.h>
#include <DS_Common/Tree/BinaryTree.h>
//====================================================================================================


/* Definition */
//====================================================================================================
//====================================================================================================

/* Class */
//====================================================================================================

namespace DS_Common {
	template<typename T>
	class  DS_COMMON_EXPORTS PriorityQueue
	{
	private: // variable
		std::vector<T> heap;
		int heapSize;

	public: // function
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Constructor
		*
		*/
		PriorityQueue(int n = 3); // n=1, 4 may cause resize error in low probability, why?
		//-----------------------------------------------------------------------------------------
		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      return the top.
		*
		*/
		const T& top();
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
		bool isempty() { return heapSize==0; };
		//-----------------------------------------------------------------------------------------

		//-----------------------------------------------------------------------------------------
		/*!
		*  @brief      Destructor
		*
		*/
		~PriorityQueue() {}
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
	PriorityQueue<T>::PriorityQueue(int n)
	{
		if (n < 1) throw "Capacity or Priority Queue must be >=1.";
		heap = std::vector<T>(n + 1);// heap[0] is not used.
		heapSize = 0;
	}
	//------------------------------------------------------------------------------------------------
	
	template<typename T>
	void PriorityQueue<T>::push(const T& e) {

		if (heapSize == heap.size())
		{
			//std::cout << "before"<<heapSize<<","<<heap.size();
			try {
				heap.resize(2 * heap.size());
			}
			catch (const char  * e)
			{
				std::cout << e << std::endl;
			}
			//std::cout << "after";
		}
		int curNode = ++heapSize;
		while (curNode != 1 && heap[curNode / 2] < e) // bobbling up.
		{
			heap[curNode] = heap[curNode / 2];
			curNode /= 2;
		}
		heap[curNode] = e;
	}
	//------------------------------------------------------------------------------------------------

	template<typename T>
	void PriorityQueue<T>::pop() {
		if (isempty()) throw "Heap is empty. Cannot Pop.";
		
		heap[1].~T(); // remove the max;

		T lastE = heap[heapSize];
		heapSize--;

		int cur = 1;
		int child = 2;
		while (child <= heapSize)
		{
			if (child < heapSize && heap[child] < heap[child + 1]) child++; // two child choose the largest.
			if (lastE >= heap[child]) break;

			heap[cur] = heap[child];
			cur = child;
			child *= 2;// next level;
		}
		heap[cur] = lastE;
	}
	//------------------------------------------------------------------------------------------------

	template<typename T>
	const T&  PriorityQueue<T>::top() {
		if (heapSize > 0)
			return heap[1];
		else
			return T();
	}
	//------------------------------------------------------------------------------------------------
}
//====================================================================================================
#endif /* __DS_COMMON_PRIORITY_QUEUE_H__ */
