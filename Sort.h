/*
 * Sort.h
 *
 *  Created on: Dec 27, 2018
 *      Author: Gouravi
 */
#ifndef SORT_H_
#define SORT_H_

#include<vector>

using namespace std;

enum enumAlogrithm {
	eUnknown,
	eHeap,
	eMerge
};


extern enumAlogrithm hashit (const char* inString);

class SortAlgorithm
{
public:
	SortAlgorithm(){};
	virtual ~SortAlgorithm(){};
	virtual void Sort(std::vector<char>& vec)=0;
};


extern SortAlgorithm* GetSortAlgorithm(const char* inString);

class MergeSort : public SortAlgorithm
{
public:
	MergeSort(){};
	void Sort(std::vector<char>& vec);
	void MergeSortRecur(int *a, int low, int high);
	void Merge(int *a, int low, int high, int mid);
};


class HeapSort : public SortAlgorithm
{
public:
    HeapSort(){}
    void Sort(std::vector<char>& vec);   
private:
    void heapify(int arr[], int n, int i);
    void heap_sort(int arr[], int n);
};

#endif /* SORT_H_ */
