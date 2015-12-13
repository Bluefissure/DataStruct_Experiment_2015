#pragma once
#ifndef BinaryTree_
#define BinaryTree_
#define max(a,b) ((a>b)?a:b)
#include<iostream>
#include<queue>
using namespace std;
class node //node of BinaryTree
{
public:
	node() { lson = rson = NULL; };
	node(int x) {
		val = x;
		lson = rson = NULL;
	}
	int val;
	node *lson, *rson;
};
class BinaryTree
{
public:
	BinaryTree() {};
	BinaryTree(node *rt) {
		root = rt;
	}
	void pre_order() { pre_order(root); }
	void in_order() { in_order(root); }
	void post_order() { post_order(root); }
	void level_order() { level_order(root); }
	void pre_order(node *rt);
	void in_order(node *rt);
	void post_order(node *rt);
	void level_order(node *rt);
	int getcount(node *rt);
	int getheight(node *rt, int level);
	void read_pre_in(int pre[], int in[], int len) {
		read_pre_in(root, pre, in, len);
	}
	BinaryTree& read_pre_in(node *rt, int pre[], int in[], int len);
	BinaryTree& read_tree();
	node *root;
};

void BinaryTree::in_order(node *rt)
{
	if (rt->lson)
		in_order(rt->lson);//Recursive
	cout << rt->val << " ";
	if (rt->rson)
		in_order(rt->rson);//Recursive
}
void BinaryTree::pre_order(node *rt)
{
	cout << rt->val << " ";
	if (rt->lson)
		pre_order(rt->lson);//Recursive
	if (rt->rson)
		pre_order(rt->rson);//Recursive
}
void BinaryTree::post_order(node *rt)
{
	if (!rt) return;
	if (rt->lson)
		post_order(rt->lson);//Recursive
	if (rt->rson)
		post_order(rt->rson);//Recursive
	cout << rt->val << " ";
}

int BinaryTree::getcount(node *rt)
{
	int ans = 0;
	if (rt)
		ans++;
	if (rt->lson)
		ans += getcount(rt->lson);//Recursive
	if (rt->rson)
		ans += getcount(rt->rson);//Recursive
	return ans;
}
int BinaryTree::getheight(node *rt, int deep)
{
	int h = deep;
	if (rt->lson)
		h = max(deep, getheight(rt->lson, deep) + 1);//Recursive
	if (rt->rson)
		h = max(deep, getheight(rt->rson, deep) + 1);//Recursive
	return h;
}
void BinaryTree::level_order(node *rt)
{
	queue<node*> Q;
	Q.push(rt);
	while (!Q.empty()) {
		node *p = Q.front();
		Q.pop();
		if (!p) continue;
		cout << p->val << " ";
		if (p->lson)
			Q.push(p->lson);//Add next level
		if (p->rson)
			Q.push(p->rson);//Add next level
	}
}

BinaryTree& BinaryTree::read_pre_in(node *rt, int pre[], int in[], int len)
{
	if (!rt) {  //if rt is root 
		root = rt = new node(pre[0]);
	}
	else {
		rt->val = pre[0]; //rt is the root of a sub-tree
	}
	int p = 0;
	for (int i = 0; i < len; i++) {
		if (in[i] == pre[0]) {
			p = i; //find rt of sub-tree in sequence pre
		}
	}
	if (p>0) {
		if (!rt->lson) {
			rt->lson = new node();
		}
		read_pre_in(rt->lson, pre + 1, in, p); //recursive handling left sub-tree
	}
	if (len - p - 1>0) {
		if (!rt->rson) {
			rt->rson = new node();
		}
		read_pre_in(rt->rson, pre + p + 1, in + p + 1, len - p - 1);//recursive handling right sub-tree
	}
	return *this;
}
const int MaxSize = 10010;
BinaryTree& BinaryTree::read_tree()
{
	cout << "Please input the numbers of nodes:";
	int n, tmp;
	cin >> n;
	char tmp_char[1010];
	node *store[MaxSize];
	cout << "Please input the tree:\n";
	for (int i = 1; i <= n; i++) {
		store[i] = NULL;
		cin >> tmp_char;
		if (strlen(tmp_char) == 1 && tmp_char[0] == '0') {  //if val = 0
			tmp = 0;
			store[i] = new node(tmp);
		}
		if (tmp = atoi(tmp_char))    //if can be tranlate into number
			store[i] = new node(tmp);
	}
	root = store[1];
	for (int i = 2; i <= n; i++) {  //transform pointer array to Chain representation
		if (i % 2) {
			if (store[i] && store[i >> 1])
				store[i >> 1]->rson = store[i];
		}
		else {
			if (store[i] && store[i >> 1])
				store[i >> 1]->lson = store[i];
		}
	}
	return *this;
}
#endif


