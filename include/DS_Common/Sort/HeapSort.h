// HeapSort.h

#ifndef __DS_COMMON_HEAPSORT_H__
#define __DS_COMMON_HEAPSORT_H__

/* Information */
//====================================================================================================

/*!
*  @file   HeapSort.h
*
*  @brief  Heap Sort.
*
*  @author Po-Wei Huang
*
*  @date   2021/05/26
*/

//====================================================================================================


/* Header */
//====================================================================================================
#include <iostream>

#include <DS_Common/Common/Common.h>
#include <DS_Common/LibSetting/LibSetting.h>
#include <queue>
#include <DS_Common/Queue/PriorityQueue.h>
//====================================================================================================


/* Public Function */
//====================================================================================================

namespace DS_Common {
	//--------------------------------------------------------------------------------------------
	template<class T>
	int Adjust(T* a, const int root, const int n)
	{
		T e = a[root];
		for (int j = 2 * root; j <= n; j *= 2)
		{
			if (j < n && a[j] < a[j + 1]) j++;

		}
	}
	//--------------------------------------------------------------------------------------------
	template<class T>
	void HeapSort(T* a, const int n)
	{
		//std::priority_queue<T> q;
		PriorityQueue<T> * q=new PriorityQueue<T>();
		for (int i = 0; i < n; i++)
		{
			q->push(a[i]);
		}

		for (int i = n-1;i>=0;i--)
		{
			a[i] = q->top();
			q->pop();
		}

		delete q;
	}
	//--------------------------------------------------------------------------------------------	
}
//====================================================================================================


#endif /* __DS_COMMON_HEAPSORT_H__ */