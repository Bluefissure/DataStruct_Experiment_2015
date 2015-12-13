#pragma once
#ifndef SparseMatrix_
#define SparseMatrix_
#include "MyExceptions.h"
template<class T>
struct Term {
	int row, col;
	T value;
};

template<class T>
class SparseMatrix
{
public:
	SparseMatrix(int maxTerms = 10);
	~SparseMatrix() { delete[] a; }
	SparseMatrix<T>& SparseMatrix<T>::Trans();
	void SparseMatrix<T>::Add(const SparseMatrix<T> &b, SparseMatrix<T> &c) const;
	void input();
	void output();
	void Append(const Term<T> &t);
	int rows, cols;
	int terms;
	Term<T> *a;
	int MaxTerms;
};

template<class T>
SparseMatrix<T>::SparseMatrix(int maxTerms)
{
	if (maxTerms<1) {
		throw OutofBounds();
	}
	MaxTerms = maxTerms;
	a = new Term<T>[MaxTerms];
	terms = rows = cols = 0;
}


template<class T>
void SparseMatrix<T>::output()
{
	//cout << "rows = " << rows << "columns = " << cols << endl;
	//cout << "nonzero terms = " << terms << endl;
	const int MAXN = 101;
	int tmp[MAXN][MAXN];

	for (int i = 0; i<rows; i++) {
		for (int j = 0; j<cols; j++) {

			tmp[i][j] = 0;
		}
	}

	for (int i = 0; i < terms; i++) {
		//	cout << "a(" << a[i].row << "," << a[i].col << ")=" << a[i].value << endl;
		tmp[a[i].row - 1][a[i].col - 1] = a[i].value;
	}

	for (int i = 0; i<rows; i++) {
		for (int j = 0; j<cols; j++) {
			cout << tmp[i][j] << " ";
		}
		cout << endl;
	}

}

template<class T>
void SparseMatrix<T>::input()
{
	cout << "Enter number of rows, columns, and elements" << endl;
	cin >> rows >> cols >> terms;
	if (terms > MaxTerms) {
		throw NoMem();
	}
	for (int i = 0; i<terms; i++) {
		cout << "Enter row, column, and value of term:" << (i + 1) << endl;
		cin >> a[i].row >> a[i].col >> a[i].value;
	}
}

template<class T>
SparseMatrix<T>& SparseMatrix<T>::Trans()
{
	for (int i = 0; i < terms; i++) {
		int t = a[i].row;
		a[i].row = a[i].col;
		a[i].col = t;
	}
	return *this;
}

template<class T>
void SparseMatrix<T>::Append(const Term<T> &x)
{
	if (terms >= MaxTerms) {
		throw NoMem();
	}
	a[terms] = x;
	terms++;
}
template<class T>
void SparseMatrix<T>::Add(const SparseMatrix<T> &b, SparseMatrix<T> &c) const
{
	if (rows != b.rows || cols != b.cols) {
		throw matrixSizeMismatch();
	}
	c.rows = rows;
	c.cols = cols;
	c.terms = 0;
	int ct = 0, cb = 0;
	while (ct < terms && cb< b.terms) {
		int indt = a[ct].row * cols + a[ct].col;
		int indb = b.a[cb].row * cols + b.a[cb].col;
		if (indt < indb) {
			c.Append(a[ct]);
			ct++;
		}
		else {
			if (indt == indb) {
				if (a[ct].value + b.a[cb].value) {
					Term<T> t;
					t.row = a[ct].row;
					t.col = a[ct].col;
					t.value = a[ct].value + b.a[cb].value;
					c.Append(t);
				}
				ct++; cb++;
			}
			else
			{
				c.Append(b.a[cb]);
				cb++;
			}
		}
	}
	for (; ct<terms; ct++) {
		c.Append(a[ct]);
	}
	for (; cb < b.terms; cb++) {
		c.Append(b.a[cb]);
	}
}

#endif