/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-31 14:07:20
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    double sum=0,ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        sum+=a[i];
        if(b[i]) ans+=0.8*a[i]; else ans+=a[i];
    }
    double save=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&c[i],&d[i]);
        if(sum>=c[i]) save=max(save,(double)d[i]);
    }
    printf("%.2f\n",min(sum-save,ans));
    return 0;
}

