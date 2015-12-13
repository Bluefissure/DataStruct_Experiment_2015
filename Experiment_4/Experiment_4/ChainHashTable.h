#pragma once
#ifndef ChainHashTable_
#define ChainHashTable_
template<class E, class K>
struct SortedChainNode {
	K key;
	E element;
	SortedChainNode<E, K> *link;
};

template<class E, class K>
class SortedChain {
public:
	SortedChain() { first = 0; }
	//~SortedChain();
	bool IsEmpty() const { return first == 0; }
	int Length() const;
	bool Search(const K& k, E& e) const;
	SortedChain<E, K>& Delete(const K& k, E& e);
	SortedChain<E, K>& Insert(const E& e);

	SortedChainNode<E, K> *first;
};

template<class E, class K>
bool SortedChain<E, K>::Search(const K& k, E &e) const
{
	SortedChainNode<E, K> *p = first;
	for (; p && p->element < k; p = p->link);
	if (p && p->element == k) {
		e = p->element;
		return true;
	}
	return false;
}

template<class E, class K>
SortedChain<E, K>& SortedChain<E, K>::Insert(const E& e)
{
	SortedChainNode<E, K> *p = first, *tp = 0;
	for (; p && p->element < e; tp = p, p = p->link);

	SortedChainNode<E, K> *q = new SortedChainNode<E, K>;
	q->element = e;

	q->link = p;
	if (tp) {
		tp->link = q;
	}
	else
		first = q;

	return *this;
}
template<class E, class K>
class ChainHashTable {
public:
	ChainHashTable(int divisor = 10)
	{
		D = divisor;
		ht = new SortedChain<E, K>[D];
	}
	~ChainHashTable() { delete[] ht; }
	bool Search(const K& k, E& e) const
	{
		return ht[k%D].Search(k, e);
	}
	ChainHashTable<E, K>& Insert(const E& e)
	{
		ht[e%D].Insert(e);
		return *this;
	}
	void Output() const {
		for (int i = 0; i<D; i++) {
			cout << "Chain " << i + 1 << " :";
			SortedChain<E, K> tmp = ht[i];
			SortedChainNode<E, K> *p = tmp.first;
			for (; p && p->element; p = p->link) {
				cout << p->element << " ";
			}
			cout << endl;
		}
	}
	int D;
	SortedChain<E, K> *ht;
};

#endif