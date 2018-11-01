/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-01 18:07:22
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
int T,n,k,a[MAXN];
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
}
int main()
{
    f[1][1]=1;
    for(int i=2;i<=100;i++)
    {
        f[i][1]=f[i][i]=i;
        for(int j=2;j<=i-1;j++) f[i][j]=f[i-1][j]+f[i-1][j-1]+1;
    }
    for(int i=1;i<=10;i++) printf("%d ",f[10][i]);
    return 0;
}

