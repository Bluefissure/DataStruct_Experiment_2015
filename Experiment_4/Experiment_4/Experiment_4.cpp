// Experiment_4.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstdlib>
#include"TridiagonalMatrix.h"
#include"LowerMatrix.h"
#include"SparseMatrix.h"
#include"HashTable.h"
#include"ChainHashTable.h"

int random(int n) {
	return rand() % n;
}
int main()
{
	int n;
	puts("TridiagonalMatrix:");
	puts("Please input n:");
	cin >> n;
	TridiagonalMatrix<int> A(n);
	puts("Please input x,i,j to store in A: (i==-1 and j==-1 to exit)");
	int x, i, j;
	while (cin >> x >> i >> j) {
		if (i == -1 && j == -1)break;
		A.Store(x, i, j);
		puts("A:");
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				cout << A.Retrieve(i, j) << " ";
			}
			cout << endl;
		}
		puts("Please input x,i,j to store in A: (i==-1 and j==-1 to exit)");
	}

	puts("LowerMatrix:");
	puts("Please input n:");
	cin >> n;
	LowerMatrix<int> L(6);
	puts("Please input x,i,j to store in L: (i==-1 and j==-1 to exit)");
	while (cin >> x >> i >> j) {
		if (i == -1 && j == -1)break;
		L.Store(x, i, j);
		puts("L:");
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				cout << L.Retrieve(i, j) << " ";
			}
			cout << endl;
		}
		puts("Please input x,i,j to store in L: (i==-1 and j==-1 to exit)");
	}

	puts("SparseMatrix:");
	SparseMatrix<int> ma, mb;
	ma.input();
	cout << "Ma:" << endl;
	ma.output();
	cout << "Ma.Trans():" << endl;
	ma.Trans().output();
	ma.Trans();

	mb.input();
	cout << "Mb:" << endl;
	mb.output();
	cout << "Ma + Mb :" << endl;
	SparseMatrix<int> mc;
	ma.Add(mb, mc);
	mc.output();


	puts("HashTable:");
	HashTable<int, int> *test = new HashTable<int, int>(961);

	for (int i = 0; i < 500; i++) {
		int x = random(1000);
		test->Insert(x);
	}
	cout << "Already added 500 numbers.\n";
	int count = 0;
	for (int j = 0; j < 961; j++) {
		if (!test->empty[j]) {
			count++;
		}
	}
	for (int k = 0; k<10; k++) {
		int x = random(1000);
		int y;
		if (test->Search(x, y)) {
			cout << "Found " << x << " at£º";
			cout << test->hSearch(x) << endl;
		}
		else
			cout << "Do not exist." << endl;
	}


	puts("ChainHashTable:");

	ChainHashTable<int, int> *CHash = new ChainHashTable<int, int>(961);
	for (int i = 0; i < 500; i++) {
		int x = random(1000);
		CHash->Insert(x);
	}
	cout << "Already added 500 numbers.\n";
	cout << "Will you view the Chain?[y/n]\n";
	CHash->Output();
	for (int j = 0; j<10; j++) {
		int x = random(1000);
		int y;
		if (CHash->Search(x, y)) {
			cout << "Found " << x << " at Chain " << y % 961 << endl;
		}
		else
			cout << x << " do not exist" << endl;
	}
	return 0;
}