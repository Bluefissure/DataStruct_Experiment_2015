// DataStruct_Experiment6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include"BinaryTree.h"
using namespace std;

int main()
{
	BinaryTree T;
	T.read_tree();
	cout << "T.level_order: ";
	T.level_order();
	cout << endl;
	cout << "T.pre_order: ";
	T.pre_order();
	cout << endl;
	cout << "T.in_order: ";
	T.in_order();
	cout << endl;
	cout << "T.post_order: ";
	T.post_order();
	cout << endl;
	printf("T.level:%d  T.count:%d\n", T.getheight(T.root, 1), T.getcount(T.root));

	BinaryTree TT;
	cout << "Please input the numbers:";
	int n;
	cin >> n;
	const int MaxSize = 10010;
	int pre[MaxSize], in[MaxSize];
	cout << "Please input the pre_order:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> pre[i];
	}
	cout << "Please input the in_order:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
	}
	TT.read_pre_in(pre, in, n);
	cout << "TT.pre_order: ";
	TT.pre_order();
	cout << endl;
	cout << "TT.in_order: ";
	TT.in_order();
	cout << endl;
	cout << "TT.post_order: ";
	TT.post_order();
	cout << endl;

	return 0;
}
