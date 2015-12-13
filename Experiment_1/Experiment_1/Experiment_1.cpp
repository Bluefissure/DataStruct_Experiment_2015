#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,cnt;
void Permutation_STL(int *num,int n)
{
	sort(num,num+n);
	do{
		for(int i=0;i<n;i++){
			printf("%d ",num[i]);
		}puts("");
		cnt++;
	}while(next_permutation(num,num+n));
}
void Permutation_Custom(int *num,int k,int n)
{
	if(k>=n){
		for(int i=0;i<n;i++){
			printf("%d ",num[i]);
		}puts("");
		cnt++;
	}
	else{
		for(int i=k;i<n;i++){
			swap(num[i],num[k]);
			Permutation_Custom(num,k+1,n);
			swap(num[i],num[k]);
		}
	}
}
int main()
{
	puts("Please input n:");
	scanf("%d",&n);
	printf("Please input %d numbers:\n",n);
	int num[n];
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	cnt=0;
	puts("Permutation_STL as follow:");
	Permutation_STL(num,n);
	printf("tot_STL:%d\n",cnt);
	system("pause");
	cnt=0;
	puts("Permutation_Custom as follow:");
	Permutation_Custom(num,0,n);
	printf("tot_Custom:%d\n",cnt);
	return 0;
}