/*Sort.h*/
#ifndef Sort_
#define Sort_
using namespace std;

template<class T>
class Sort
{
public:
	Sort() {};
	~Sort() {};
	void Swap(T *a, T *b) {
		T t = *b;
		*b = *a;
		*a = t;
	}
	T* BubbleSort(T *begin, T *end)
	{
		T *p, *pp;
		for (p = begin; p < end; p++) {
			for (pp = p + 1; pp < end; pp++) {
				if (*p > *pp) {
					Swap(p, pp);
				}
			}
		}
		return begin;
	}
	T* SelectionSort(T *begin, T *end) {
		T *p, *pp, *ind;
		for (p = begin; p < end; p++) {
			ind = p;
			for (pp = p + 1; pp < end; pp++) {
				if (*ind > *pp) {
					ind = pp;
				}
			}
			Swap(p, ind);
		}
		return begin;
	}
	T* InsertSort(T* begin, T* end) {
		T *p, *pp, t;
		for (p = begin + 1; p < end; p++) {
			if (*p < *(p - 1)) {
				t = *p;
				for (pp = p - 1; pp >= begin && (*pp) > t; pp--) {
					*(pp + 1) = *pp;
				}
				*(pp + 1) = t;
			}
		}
		return begin;
	}
	T* QuickSort(T* left, T* right) {
		if (left < right) {
			T *i = left, *j = right, x = *i;
			while (i < j) {
				while (i < j && (*j) >= x) j--;
				if (i < j) *(i++) = *j;
				while (i < j && (*i) < x) i++;
				if (i < j) *(j--) = *i;

			}
			*i = x;
			QuickSort(left, i - 1);
			QuickSort(i + 1, right);
		}
		return left;
	}



	int getval(int num, int pos)
	{
		int temp = 1;
		for (int i = 0; i < pos - 1; i++)
			temp *= 10;
		return (num / temp) % 10;
	}


	int* RadixSort(int* p, int num)
	{
		const int base = 10, bits = 31; //10-based number, 31 bits
		int *tmp[base];
		for (int i = 0; i < 10; i++)
		{
			tmp[i] = (int *)malloc(sizeof(int) * (num + 1));
			tmp[i][0] = 0;    //tmp[i][0] to store the tot_num
		}

		for (int pos = 1; pos <= bits; pos++)
		{
			for (int i = 0; i < num; i++)
			{
				int num = getval(p[i], pos);
				int index = ++tmp[num][0];
				tmp[num][index] = p[i];
			}

			for (int i = 0, j = 0; i < base; i++)
			{
				for (int k = 1; k <= tmp[i][0]; k++)
					p[j++] = tmp[i][k];
				tmp[i][0] = 0;    // init 
			}
		}
		return p;
	}

	void Merge(T *array, const int l, const int mid, const int r)
	{
		int i, index, l1, r1, l2, r2;
		T *tmp;
		int len = r - l + 1;
		tmp = (T *)malloc(sizeof(T)*len);
		if (tmp == NULL) return;
		l1 = l; r1 = mid;
		l2 = mid + 1; r2 = r;
		index = 0;
		while ((l1 <= r1) && (l2 <= r2)) {
			if (array[l1] < array[l2]) {
				tmp[index++] = array[l1];
				l1++;
			}
			else {
				tmp[index++] = array[l2];
				l2++;
			}
		}
		while (l1 <= r1)
			tmp[index++] = array[l1++];
		while (l2 <= r2)
			tmp[index++] = array[l2++];
		for (i = 0; i<(r - l + 1); i++)
			array[l + i] = tmp[i];
		free(tmp);
	}

	/***  Recursion ***/
	T* MergeSort(T *a, const int l, const int r)
	{
		int mid = 0;
		if (l < r)
		{
			mid = (l + r) >> 1;
			MergeSort(a, l, mid);
			MergeSort(a, mid + 1, r);
			Merge(a, l, mid, r);
		}
		return a;
	}

	/*** No-Recurtion ***/
	T* MergeSort_(T *a, const int l, const int r)
	{
		int len = r - l + 1, l_min, l_max, r_min, r_max;
		int index;
		T *tmp;
		tmp = (T *)malloc(sizeof(T)*len);
		if (tmp == NULL || len <= 0) return;
		for (int i = 1; i < len; i <<= 1)
		{
			for (l_min = 0; l_min < len - i; l_min = r_max)
			{
				int j;
				r_min = l_max = l_min + i;
				r_max = l_max + i;
				j = l_min;
				if (r_max > len) r_max = len;
				index = 0;
				while (l_min < l_max && r_min < r_max)
					tmp[index++] = (a[l_min] > a[r_min] ? a[r_min++] : a[l_min++]);
				while (l_min < l_max)
					a[--r_min] = a[--l_max];
				while (index)
					a[--right_min] = tmp[--index];
			}
		}
		free(tmp);
		return a;
	}

};


#endif