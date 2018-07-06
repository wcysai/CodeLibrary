/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-06 09:01:04
 ************************************************************************/
#pragma GCC optimize(3)
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<assert.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,W;
vector<int> v1,v2;
int v[50];
int main()
{
    scanf("%d%d",&W,&n);
    for(ll i=0;i<n;i++)
        scanf("%d",&v[i]);
    ll t1=n/2,t2=n-t1;
    for(ll i=0;i<(1<<t1);i++)
    {
        ll sum=0;
        for(ll j=0;j<t1;j++)
        {
            if((i>>j)&1) sum+=v[j];
            if(sum>W) break;
        }
        if(sum<=W) v1.push_back(sum);
    }
    for(ll i=0;i<(1<<t2);i++)
    {
        ll sum=0;
        for(ll j=0;j<t2;j++)
        {
            if((i>>j)&1) sum+=v[t1+j];
            if(sum>W) break;
        }
        if(sum<=W) v2.push_back(sum);
    }
    v2.push_back(W+1);
    sort(v2.begin(),v2.end());
    int ans=0;
    for(int i=0;i<(int)v1.size();i++)
    {
        vector<int>::iterator it=upper_bound(v2.begin(),v2.end(),W-v1[i]);
        if (it==v2.begin()) continue;
        it--;
        ans=max(ans,v1[i]+*it);
    }
    printf("%d\n",ans);
    return 0;
}

