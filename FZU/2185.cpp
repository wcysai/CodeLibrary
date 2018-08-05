/*************************************************************************
    > File Name: 2185.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-03 19:09:34
 ************************************************************************/

#pragma GCC optimize(3)
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<cstring>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
int deg[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(deg,0,sizeof(deg));
        for(int i=0;i<n-1;i++)
        {
            int x;
            scanf("%d",&x);
            deg[i+1]++;deg[x]++;
        }
        int ans1=0,ans2=0;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==1) ans1++;
            ans2+=(deg[i]-1)/2;
        }
        if(n>1) ans2++;
        printf("%d %d\n",(ans1+1)/2,ans2);
    }
    return 0;
}

