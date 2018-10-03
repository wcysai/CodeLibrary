/*************************************************************************
    > File Name: dabiao.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-03 16:17:00
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
    while(scanf("%d%d",&k,&n)==2)
    {
    for(int i=1;i<=n;i++) a[i]=i;
    int cnt=0;
    do
    {
        bool f=true;
        for(int i=2;i<=n;i++)
            if(max(a[i]-a[i-1],a[i-1]-a[i])>k)  {f=false; break;}
        if(f) cnt++;
    }while(next_permutation(a+1,a+n+1));
    printf("%d\n",cnt);
    }
    return 0;
}

