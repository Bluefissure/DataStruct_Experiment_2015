#pragma once
#ifndef BinarysearchTree_
#define BinarysearchTree_
#include<cstdio>
#include<stdlib.h>
#include<iostream>
typedef int KeyType;
class bstnode
{
public:
	bstnode() {};
	KeyType key;          
	bstnode * lson;  
	bstnode * rson; 
	bstnode * fa;
};
class BstTree
{
public:
	bstnode* root;
	BstTree() {};
	void insert(bstnode *root, KeyType key);
	void create(KeyType *keyArray, int length);
	void in_order() {
		in_order(root);
	}
	void in_order(bstnode *rt);
};
void BstTree::insert(bstnode * rt, KeyType key)
{
	bstnode *p = new bstnode();
	p->key = key;
	p->lson = p->rson = p->fa = NULL;
	if (root == NULL) {
		root = p;
		return;
	}
	if (rt->lson == NULL && rt->key > key) {
		p->fa = rt;
		rt->lson = p;
		return;
	}
	if (rt->rson == NULL && rt->key < key) {
		p->fa = rt;
		rt->rson = p;
		return;
	}
	if (rt->key > key)
		insert(rt->lson, key);
	else if (rt->key < key)
		insert(rt->rson, key);
	else
		return;
}


void BstTree::create(KeyType *keyArray, int length)
{
	int i;
	//逐个结点插入二叉树中
	for (i = 0; i<length; i++)
		insert(root, keyArray[i]);
}
void BstTree::in_order(bstnode *rt)
{
	if (!rt) return;
	if (rt->lson) {
		in_order(rt->lson);
	}
	if (rt)
		std::cout << rt->key << " ";
	if (rt->rson) {
		in_order(rt->rson);
	}

}

#endif

