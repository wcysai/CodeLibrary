/*************************************************************************
    > File Name: test.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-08 16:36:13
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
int n,k,a[MAXN];
int main()
{
    a[0]=1;
    for(int i=1;i<=20;i++)
    {
        int sum=0;
        for(int j=i-1;j>=0;j--)
            sum+=-1*(i-j+1)*(i-j+1)*a[j];
        a[i]=sum;
        printf("%d\n",a[i]);
    }
    return 0;
}

