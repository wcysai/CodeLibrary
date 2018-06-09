/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-09 19:10:02
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
ll n,a[MAXN],b[MAXN];
vector<int> pos1,pos2;
bool valid1[MAXN],valid2[MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) 
        scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    ll ans=0;
    ll s1=n,s2=n;
    while(s1>=1&&s2>=1)
    {
        while(a[s1]==0&&s1>=1) s1--;
        s2=min(s2,s1);
        while(b[s2]==0&&s2>=1) s2--;
        ll x=min(a[s1],b[s2]);
        ans+=x*(s1-s2);
        a[s1]-=x;b[s2]-=x;
    }
    for(ll i=1;i<=n;i++)
        if(a[i]) ans+=a[i]*(i-1);
    for(ll i=1;i<=n;i++)
        if(b[i]) ans+=(b[i])*(i-1);
    printf("%lld\n",ans);
    return 0;
}

