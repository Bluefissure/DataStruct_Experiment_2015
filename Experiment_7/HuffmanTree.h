#pragma once

#ifndef HuffmanTree_
#define HuffmanTree_
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
const int MaxSize = 1010;

class hfnode
{
public:
	hfnode() {
		val = 0;
		lson = rson = 0;
	}
	hfnode(int x) {
		val = x;
		lson = rson = 0;
	}
	hfnode(int x, hfnode*ls, hfnode*rs) {
		val = x; lson = ls; rson = rs;
	}
	~hfnode() {};
	int val;
	hfnode *lson, *rson;
	char code[MaxSize];
};
struct cmp
{
	bool operator()(hfnode *a, hfnode *b) {
		return  a->val > b->val; 
	}
};
class HuffmanTree
{
public:
	HuffmanTree() {};
	HuffmanTree(hfnode *rt) {
		root = rt;
	}
	~HuffmanTree() {};
	void Input();
	void Output_code();
	void getcode() {
		dfs_code(root,"");
	};
	void dfs_code(hfnode *rt,string str);
	int n;
	hfnode *store[MaxSize];
	hfnode *root;
};


void HuffmanTree::Input() {
	puts("Please input the number of elements:");
	int tmp;
	scanf_s("%d", &n);
	priority_queue<hfnode*, vector<hfnode*>,cmp> Q;
	printf("Please intput %d element(s):\n", n);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &tmp);
		store[i] = new hfnode(tmp);
		Q.push(store[i]);
//			printf("pushing %d\n", store[i]->val);
	}
	
	while (!Q.empty()) {
		hfnode* p = Q.top(); Q.pop();
//		printf("poping %d\n", p->val);

		if (!Q.empty()) {
			hfnode* pp = Q.top(); Q.pop();
//			printf("poping %d\n", pp->val);
			Q.push(new hfnode(p->val + pp->val, p, pp));
//			printf("pushing %d\n", p->val + pp->val);
		}
		else {
			root = p;
		}
	}
}

void HuffmanTree::dfs_code(hfnode *rt,string str) {
	if (rt->lson&&rt->rson) {
		dfs_code(rt->lson, str+"0");
		dfs_code(rt->rson, str+"1");
	}
	else {
		strcpy_s(rt->code, str.c_str());
	}
}

void HuffmanTree::Output_code() {
	
	for (int i = 1; i <= n; i++) {
		printf("%d:%s\n", store[i]->val, store[i]->code);
	}
}
#endif
