#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n, cnt;
void Getsubset(int *num, bool *f, int k, int n)
{
	if (k >= n) {
		printf("{");
		bool first = 1;
		for (int i = 0; i<n; i++) {
			if (f[i]) {
				if (first) first = 0;
				else printf(" ");
				printf("%d", num[i]);
			}
		}puts("}");
		cnt++;
	}
	else {
		f[k] = 0;
		Getsubset(num, f, k + 1, n);
		f[k] = 1;
		Getsubset(num, f, k + 1, n);
	}
}
int main()
{
	puts("Please input n:");
	scanf("%d", &n);
	printf("Please input %d numbers:\n", n);
	int num[n];
	bool f[n];
	for (int i = 0; i<n; i++) {
		scanf("%d", &num[i]);
	}
	cnt = 0;
	memset(f, 0, sizeof(f));
	puts("Subset as follow:");
	Getsubset(num, f, 0, n);
	printf("tot:%d\n", cnt);
}