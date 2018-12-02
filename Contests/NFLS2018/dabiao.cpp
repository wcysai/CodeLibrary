/*************************************************************************
    > File Name: dabiao.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-29 19:55:43
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,counter;
const int maxn = 2011;
int a[maxn],b[maxn];

void quick_sort(int l, int r)
{
	counter += 3;
	int i=l, j=r, x=a[(l+r)/2];
	do
	{
		counter++;
		while (a[i]<x)
		{
			counter++;
			i++;
		}
		counter++;
		while (x<a[j])
		{
			counter++;
			j--;
		}
		counter++;
		if (i<=j)
		{
			counter++;
			swap(a[i], a[j]);
			counter++;
			i++;
			counter++;
			j--;
		}
		counter++;
	} while (i<=j);
	counter++;
	if (l<j)
	{
		counter++;
		quick_sort(l, j);
	}
	counter++;
	if (i<r)
	{
		counter++;
		quick_sort(i, r);
	}
}
int ans[maxn];
int curmax=0;
int main()
{
    srand(time(NULL));
    n=2000;
    for(int i=1;i<=2000;i++) a[i]=2001-i;
    for(int it=1;it<=2000;it++)
    {
        if(it%2000==0) printf("%d\n",it);
        random_shuffle(a+1,a+n+1);
        for(int i=1;i<=n;i++) b[i]=a[i];
        counter=0;
        quick_sort(1,n);
        if(counter>curmax) 
        {
            curmax=counter;
            for(int i=1;i<=n;i++) ans[i]=b[i];
        }
    }
    printf("%d\n",curmax);
    freopen("output.txt","w",stdout);
    printf("%d\n",2000);
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
}
