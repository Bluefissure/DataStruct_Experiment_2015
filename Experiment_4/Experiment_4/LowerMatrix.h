#pragma once
#ifndef LowerMatrix_
#define LowerMatrix_
template <class T>
class LowerMatrix {
public:
	LowerMatrix(int size = 10) {
		n = size;
		t = new T[n*(n + 1) / 2];
		for (int i = 0; i<n*(n + 1) / 2; i++)
			t[i] = 0;
	}
	~LowerMatrix() {
		delete[]t;
	}
	int getn() const { return n; }
	LowerMatrix<T>& Store(const T &x, int i, int j);
	T Retrieve(int i, int j) const;
private:
	int n;
	T *t;
};

template<class T>
LowerMatrix<T>& LowerMatrix<T>::Store(const T &x, int i, int j)
{
	if (i<1 || j<1 || i>n || j>n) throw OutofBounds();
	int k = i + (j - 1)*(2 * n - j) / 2;
	if (i >= j) t[k - 1] = x;
	else if (x != 0) cerr << "MustBeZero\n";
	return *this;
}

template<class T>
T LowerMatrix<T>::Retrieve(int i, int j) const
{
	if (i<1 || j<1 || i>n || j>n) throw OutofBounds();
	if (i >= j) return t[i + (j - 1)*(2 * n - j) / 2 - 1];
	else return 0;
}
#endif
