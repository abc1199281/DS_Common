// MergeSort.h

#ifndef __DS_COMMON_MERGESORT_H__
#define __DS_COMMON_MERGESORT_H__

/* Information */
//====================================================================================================

/*!
*  @file   MergeSort.h
*
*  @brief  MergeSort.
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
//====================================================================================================


/* Public Function */
//====================================================================================================

namespace DS_Common {
	//--------------------------------------------------------------------------------------------
	template<class T>
	int ListMerge(T* a, int* link, const int start1, const int start2)
	{
		if (start1 >= start2) return link[0];
		int iResult = 0;
		int i1 = start1;
		int i2 = start2;
		while (i1!=-1 && i2!=-1)
		{
			if (a[i1] <= a[i2]) {
				/* key in first list is lower, link this element
				   to start and change start to point to first.
				*/
				link[iResult] = i1+1; // link this element to ther start
				iResult = i1+1; // change the start to point the first
				i1 = link[i1+1]; // update the element.
			}
			else {
				link[iResult] = i2+1;
				iResult = i2+1;
				i2 = link[i2+1];
			}
		}
		if (i1 == -1) link[iResult] = i2+1;
		else link[iResult+1] = i1+1;
		return link[0];
	}
	//--------------------------------------------------------------------------------------------
	template<class T>
	int rMergeSort(T* a, int* link, const int left, const int right)
	{
		if (left >= right)
			return left;
		int mid = (left + right) / 2;
		return ListMerge(a, link,
			rMergeSort(a, link, left, mid),
			rMergeSort(a, link, mid+1, right));
	}
	//--------------------------------------------------------------------------------------------
	template<class T>
	void merge(T* a, const int left, const int mid, const int right)
	{
		int n1 = mid - left + 1;
		int n2 = right - mid;

		int *L = (int*)malloc(n1 * sizeof(int));
		int *M = (int*)malloc(n2 * sizeof(int));

		for (int i = 0; i < n1; i++)
		{
			L[i] = a[left+i];
		}
		for (int j = 0; j < n2; j++)
		{
			M[j] = a[mid+1+j];
		}
		int i=0, j=0, k= left;
		while (i < n1 && j<n2)
		{
			if (L[i] < M[j])
			{
				a[k] = L[i];
				i++;
			}
			else {
				a[k] = M[j];
				j++;
			}
			k++;
		}
		while (i < n1)
		{
			a[k++] = L[i++];
		}
		while (j < n2)
		{
			a[k++] = M[j++];
		}

		free(L);
		free(M);
	}
	//--------------------------------------------------------------------------------------------
	template<class T>
	void rMergeSort_copy(T* a, const int left, const int right)
	{
		if (left >= right) 
			return;
		int mid = (left + right) / 2;
		rMergeSort_copy(a, left, mid);
		rMergeSort_copy(a, mid+1, right);
		merge(a, left, mid, right);
	}
	//--------------------------------------------------------------------------------------------	
}
//====================================================================================================


#endif /* __DS_COMMON_MERGESORT_H__ */