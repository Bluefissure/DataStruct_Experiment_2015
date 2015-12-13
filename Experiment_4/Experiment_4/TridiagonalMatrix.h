#pragma once
#ifndef TridiagonalMatrix_
#define TridiagonalMatrix_
#include"MyExceptions.h"
template <class T>
class TridiagonalMatrix{
public:
	TridiagonalMatrix(int size = 10) {
		n = size;
		t = new T[3 * n - 2];
		for (int i = 0; i < 3 * n - 2; i++)
			t[i] = 0;
	}
	~TridiagonalMatrix() { delete[] t; }
	TridiagonalMatrix<T>& Store(const T &x, int i, int j);
	T Retrieve(int i, int j) const;
private:
	int n;
	T *t;
};

template <class T>
TridiagonalMatrix<T>& TridiagonalMatrix<T>::Store(const T &x, int i, int j)
{
	if (i<1 || i>n || j<1 || j>n) throw OutofBounds();
	if ((i - j) > 1 || (i - j) < -1) throw OutofBounds();
	t[3 * j - 2 + (i - j) - 1] = x;
	return *this;
}

template <class T>
T TridiagonalMatrix<T>::Retrieve(int i, int j) const
{
	if (i<1 || i>n || j<1 || j>n) throw OutofBounds();
	if ((i - j) > 1 || (i - j) < -1) return 0;
	return t[3 * j - 2 + (i - j) - 1];
}

#endif
