#pragma once
#ifndef Maxheap_
#define Maxheap_

template<class T>
void swap(T &x, T &y)
{
	T t = x;
	x = y;
	y = t;
}



template <class T>
class hpnode
{
public:
	hpnode() {};
	hpnode(T v) {
		val = v;
	}
	hpnode(T v,hpnode<T> *f) {
		val = v;
		fa = f;
		lson = rson = 0;
	}
	hpnode(T v, hpnode<T> *l, hpnode<T> *r) {
		val = v;
		lson = l;
		rson = r;
	}
	T val;
	hpnode *lson;
	hpnode *rson;
	hpnode *fa;
	hpnode *pre;
};

template<class T>
void pprint(hpnode<T>* x,int l) {
	if (!x) return;
	try {
//		cout << x->val << " " << l << " address:" << x << endl;
		pprint(x->lson, l + 1);
		pprint(x->rson, l + 1);
	}
	catch (...) {
		return;
	}
}

template <class T>
class MaxHeap
{
public:
	MaxHeap() {};
	~MaxHeap() {
		del(root);
	}
	void del(hpnode<T> *rt) {
		if (!rt) return;
		if (rt->lson) 
			del(rt->lson);
		if (rt->rson)
			del(rt->rson);
		if (rt)
			delete rt;
	}
	hpnode<T>* getnext(hpnode<T> *rt);
	MaxHeap& Push(T &x);
	T Pop();

	MaxHeap(hpnode<T> *rt) {
		root = rt;
	}
	hpnode<T> *root;
	hpnode<T> *last;
};


template<class T>
hpnode<T>* MaxHeap<T>::getnext(hpnode<T> *rt) {
		if (!rt) {
			root = new hpnode<T>(0);
			return root;
		}
		hpnode<T>* f = rt->fa;
		if (f) {
			if (rt == f->lson) {
				f->rson = new hpnode<T>(0, f);
				f->rson->pre = f->lson;
				return f->rson;
			}
			else {
				hpnode<T> *ff = f->fa;
				if (ff) {
					if (f == ff->lson) {
						//addleft(ff->rson);
						hpnode<T> *p = ff->rson;
						p->lson = new hpnode<T>(0, p);
						p->lson->pre = rt;
						return p->lson;
					}
				}
			}
		}
		//addleft(root);
		hpnode<T> *p = root, *ppre = root;;
		while (p->lson) p = p->lson;
		while (ppre->rson) ppre = ppre->rson;
		p->lson = new hpnode<T>(0, p);
		p->lson->pre = ppre;
		return p->lson;
}

template<class T>
MaxHeap<T>& MaxHeap<T>::Push(T &x)
{
	hpnode<T> *p = getnext(last);
//	cout << "next:" << p << endl;
	last = p;
	while (p->fa && p->fa->val < x) {
		p->val = p->fa->val;
		p = p->fa;
	}
	p->val = x;
//	cout << "Adding " << x <<" p:"<<p <<endl;
//	pprint(root, 0);
	return *this;
}

template<class T>
T MaxHeap<T>::Pop()
{
	if (!root || !last)
		return NULL;

	T x = root->val;		
	T y = last->val;

	hpnode<T>* tmp = last;
	last = last->pre;
	//cout << "last:" << tmp << " pre:" << last << endl;
	hpnode<T> *p = root,*pp=root->lson;
	while (pp)
	{
		if (p->rson && p->lson->val < p->rson->val)
			pp = p->rson;
		if (pp->val > y) {
			p->val = pp->val;
			p = pp;
			pp = p->lson;
		}
		else
			break;
	}
	p->val = y;
	delete tmp;
	return x;
}

#endif
