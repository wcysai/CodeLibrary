/*************************************************************************
    > File Name: I.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-01 18:35:28
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
typedef vector<ll> vec;
typedef vector<vec> mat;
ll T,n,m,R;
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&m,&n,&R);
        mat A(n,vec(m));
        for(ll i=0;i<m;i++) 
            for(ll j=0;j<n;j++) 
            {
                scanf("%lld",&A[j][i]);
                A[j][i]=(A[j][i]+R-1)/R;
            }
        ll ans=0;
        if(n==1) 
        {
            for(ll i=0;i<m;i++) ans+=A[0][i];
            printf("%lld\n",ans);
        }
        else
        {
            for(ll i=0;i<n-1;i++)
            {
                ll cur=0;
                for(ll j=0;j<m;j++) cur+=max(A[i][j],A[i+1][j]);
                ans=max(ans,cur);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

