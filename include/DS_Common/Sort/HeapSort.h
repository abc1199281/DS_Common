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
		int j;
		for (j = 2 * root; j <= n; j *= 2)
		{
			if (j < n && a[j] < a[j + 1]) j++;
			if (e >= a[j]) break;
			a[j / 2] = a[j];
		}
		a[j / 2] = e;
		return 1;
	}
	//--------------------------------------------------------------------------------------------
	template<class T>
	void HeapSortNaive(T* a, const int n)
	{
		int i;
		for (i = n / 2; i >= 1; i--)
			Adjust(a, i, n);
		for (i = n - 1; i >= 1; i--)
		{
			std::swap(a[1],a[i+1]);
			Adjust(a, 1, i);
		}
	}
	//--------------------------------------------------------------------------------------------
	template<class T>
	void HeapSort(T* a, const int n)
	{
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