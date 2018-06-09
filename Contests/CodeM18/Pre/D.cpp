/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-31 14:38:30
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXM 6
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define eps 1e-10
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
ll n,m,k,C;
ll score[MAXM][MAXN],weight[MAXM],save[MAXM];
bool mark[MAXN];
ll now[MAXN];
P rating[MAXN];
ll cnt[MAXN];
int main()
{
    scanf("%lld%lld%lld%lld",&n,&m,&k,&C);
    memset(mark,false,sizeof(mark));
    ll sum=0;
    for(ll i=0;i<m;i++) 
        scanf("%lld",&weight[i]);
    ll pid=-1,rid=-1;
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
        {
            scanf("%lld",&score[j][i]);
            if(score[j][i]==-1) 
            {
                pid=i;
                rid=j;
            }
        }
    ll denom=1;
    for(ll i=0;i<m;i++)
    {
        if(i==rid) continue;
        ll res=0;
        for(ll j=0;j<n;j++)
            res=max(res,score[i][j]);
        save[i]=res;
        if(res==0) continue;
        denom*=res;
    }
    for(ll i=0;i<m;i++)
    {
        if(i==rid||save[i]==0) continue;
        for(ll j=0;j<n;j++)
            now[j]+=score[i][j]*denom/save[i]*weight[i];
    }
    for(ll i=0;i<=C;i++)
    {
        score[rid][pid]=i;
        ll res=0;
        for(ll j=0;j<n;j++)
            res=max(res,score[rid][j]);
        if(res==0)
        {
            for(ll j=0;j<n;j++)
            {
                rating[j].F=now[j];
                rating[j].S=j;
            }
        }
        else
        {
            for(ll j=0;j<n;j++)
            {
                rating[j].F=now[j]*res+denom*score[rid][j]*weight[rid];
                rating[j].S=j;
            }
        }
        sort(rating,rating+n);
        for(ll j=n-1;j>n-1-k;j--)
            cnt[rating[j].S]++;
        if(n==k) continue;
        if(rating[n-k].F==rating[n-1-k].F)
        {
            ll lid=INF,rid=-INF;
            for(ll i=0;i<n;i++)
                if(rating[i].F==rating[n-k].F)
                {
                    lid=min(lid,i);
                    rid=max(rid,i);
                }
            for(ll i=lid;i<=rid;i++)
                mark[rating[i].S]=true;
        }
    }
    for(ll i=0;i<n;i++)
    {
        if(mark[i]) printf("3");
        else if(cnt[i]==C+1) printf("1");
        else if(cnt[i]==0) printf("2");
        else printf("3");
        printf("\n");
    }
    return 0;
}

