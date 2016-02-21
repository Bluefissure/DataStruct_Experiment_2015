// Experiment_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"MaxHeap.h"
#include"HuffmanTree.h"
#include"BinarysearchTree.h"
#include<cstring>
#include<string>
using namespace std;


int main()
{
	puts("Heap:");
	MaxHeap<int> h;
	cout << "Please input number n:";
	int n,tmp;
	cin >> n;
	cout << "Please input n numbers:\n";
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		h.Push(tmp);
	}
	pprint(h.root,0);
	while (h.root&&h.last) {
		cout << h.Pop() << " ";
	}cout << endl;

	puts("HuffmanTree:");
	HuffmanTree hf;
	hf.Input();
	hf.getcode();
	hf.Output_code();
	puts("BinarySearchTree:");
	cout << "Please input number n:";
	cin >> n;
	int num[10100];
	cout << "Please input n numbers:\n";
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	BstTree bst;
	bst.create(num, n);
	bst.in_order();
	puts("");
	


    return 0;
}

