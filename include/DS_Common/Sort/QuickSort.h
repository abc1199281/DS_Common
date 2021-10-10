// QuickSort.h

#ifndef __DS_COMMON_QUICKSORT_H__
#define __DS_COMMON_QUICKSORT_H__

/* Information */
//====================================================================================================

/*!
*  @file   QuickSort.h
*
*  @brief  QuickSort.
*
*  @author Po-Wei Huang
*
*  @date   2021/05/26
*/

//====================================================================================================


/* Header */
//====================================================================================================
#include <iostream>
#include <algorithm>

#include <DS_Common/Common/Common.h>
#include <DS_Common/LibSetting/LibSetting.h>
//====================================================================================================


/* Public Function */
//====================================================================================================

namespace DS_Common {
	//--------------------------------------------------------------------------------------------
	template <class T>
	void QuickSort(T* a, const int left, const int right)
	{
		// a[left, right] do incremental sort
		// left as initial pivot, i, j for seperation sub string
		// for any time, a[m]<= pivot, m<i, && a[m]>=pivot, m>j
		// we assume a[left]<=a[right+1]
		if (left < right)
		{
			int i = left;
			int j = right+1;
			int pivot = a[left];

			do {
				
				do i++; while (a[i] < pivot && i<right);
				do j--; while (a[j] > pivot && j>0);
				if (i < j) std::swap(a[i],a[j]);
			} while (i < j);
			std::swap(a[left],a[j]);

			QuickSort(a, left, j-1);
			QuickSort(a, j+1, right);
		}
	}

	//--------------------------------------------------------------------------------------------	
}
//====================================================================================================


#endif /* __DS_COMMON_QUICKSORT_H__ */