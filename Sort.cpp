/*
 * Sort.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: Gouravi
 */


#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Sort.h"

using namespace std;

enumAlogrithm StrToEnum(const char* inString)
{
	if(!strcmp(inString, "Heapsort")) 
		return eHeap;
	if(!strcmp(inString, "Mergesort")) 
		return eMerge;
	return eUnknown;	
}

    SortAlgorithm* GetSortAlgorithm(const char* inString)
    {
            switch (StrToEnum(inString))
            {
            case eHeap:
                return new HeapSort();
                break;

            case eMerge: {cout<<"Merge switch"<<endl;
                return new MergeSort();
                break;}

            case eUnknown: break;
            };
        cout<<"end switch"<<endl;
            return 0;
    }


// A function to merge the two half into a sorted data.
void MergeSort::Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

// A function to split array into two parts.
void MergeSort::MergeSortRecur(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSortRecur(a, low, mid);
		MergeSortRecur(a, mid+1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}

void MergeSort::Sort(std::vector<char>& vec)
{
	int n = vec.size();
	int arr[n];

	for (int i = 0; i < n; i++) //todo 
        arr[i]= vec[i] - '0';

	MergeSortRecur(arr, 0, n-1);

	// store back the sorted data.
	for (int i = 0; i < n; i++)
        vec[i] = arr[i] + 48;
	cout<<endl;
}


void HeapSort::heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
 
// main function to do heap sort
void HeapSort::heap_sort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


void HeapSort::Sort(std::vector<char>& vec)
{
    int n = vec.size();  //todo
    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i]= vec[i] - '0';
   
    heap_sort(arr,n);

    // store back the sorted data.
    for (int i = 0; i < n; i++)
        vec[i] = arr[i] + 48;
}
