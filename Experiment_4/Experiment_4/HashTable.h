
#pragma once
#ifndef HashTable_
#define HashTable_

template<class E, class K>
class HashTable {
public:
	HashTable(int divisor = 11);
	~HashTable() { delete[] ht; delete[] empty; }
	bool Search(const K& k, E& e) const;
	HashTable<E, K>& Insert(const E& e);


	int hSearch(const K& k) const;
	int D;
	E *ht; 
	bool *empty;
};

template<class E, class K>
HashTable<E, K>::HashTable(int divisor)
{
	D = divisor;
	ht = new E[D];
	empty = new bool[D];
	for (int i = 0; i<D; i++) {
		empty[i] = true;
	}
}

template<class E, class K>
int HashTable<E, K>::hSearch(const K& k) const
{

	int i = k%D; 
	int j = i;
	do {
		if (empty[j] || ht[j] == k) {
			return j;
		}
		j = (j + 1) % D; 
	} while (j != i); 
	return j; 
}

template<class E, class K>
bool HashTable<E, K>::Search(const K& k, E &e) const
{

	int b = hSearch(k);
	if (empty[b] || ht[b] != k) {
		return false;
	}
	e = ht[b];
	return true;
}

template<class E, class K>
HashTable<E, K>& HashTable<E, K>::Insert(const E& e)
{

	K k = e; 
	int b = hSearch(k);

	if (empty[b]) {
		empty[b] = false;
		ht[b] = e;
		return *this;
	}

	if (ht[b] == k) {
		int count = 0;
		while (count < D) {
			b = (b + 1) % D;
			count++;
			if (empty[b]) {
				empty[b] = false;
				ht[b] = e;
				return *this;
			}
		}
		//throw BadInput();
	}
	else {
		throw NoMem();
	}
	return *this;
}

#endif