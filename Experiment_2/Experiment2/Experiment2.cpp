// DataStruct_Experiment_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include "Sort.h"
using namespace std;


int num[10010], sorted[10010];
void display(int *num, int n)
{
	for (int i = 0; i < n; i++) {
		cout << num[i] << " ";
	}
	cout << endl;
}
int main()
{
	printf("Please input the number of elements:");
	int n;
	cin >> n;
	puts("Please input numbers:");
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	Sort<int> ss;

	memcpy(sorted, num, n*sizeof(int));
	puts("Origional array:");
	display(sorted, n);

	ss.BubbleSort(sorted, sorted + n);
	puts("After BubbleSort:");
	display(sorted, n);

	memcpy(sorted, num, n*sizeof(int));
	ss.InsertSort(sorted, sorted + n);
	puts("After InsertSort:");
	display(sorted, n);

	memcpy(sorted, num, n*sizeof(int));
	ss.SelectionSort(sorted, sorted + n);
	puts("After SelectionSort:");
	display(sorted, n);

	memcpy(sorted, num, n*sizeof(int));
	ss.QuickSort(sorted, sorted + n - 1);
	puts("After QuickSort:");
	display(sorted, n);

	memcpy(sorted, num, n*sizeof(int));
	ss.RadixSort(sorted, n);
	puts("After RadixSort:");
	display(sorted, n);

	memcpy(sorted, num, n*sizeof(int));
	ss.MergeSort(sorted, 0, n - 1);
	puts("After MergeSort:");
	display(sorted, n);

	memcpy(sorted, num, n*sizeof(int));
	ss.MergeSort(sorted, 0, n - 1);
	puts("After No-Recurtion MergeSort:");
	display(sorted, n);
	
    return 0;
}