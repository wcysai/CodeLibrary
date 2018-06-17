/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-17 14:19:27
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
ll query;
string s,t;
ll cnt[26];
ll fact[MAXN],invf[MAXN];
ll pow_mod(ll a,ll i)
{
    ll s=1;
    if(i==0) return 1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%lld",&query);
    fact[0]=invf[0]=1;
    for(ll i=1;i<=100000;i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(ll i=99999;i>=1;i--)
        invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    while(query--)
    {
        cin>>s;cin>>t;
        memset(cnt,0,sizeof(cnt));
        for(ll i=0;i<(int)s.size();i++)
            cnt[s[i]-'a']++;
        for(ll i=0;i<(int)t.size();i++)
            cnt[t[i]-'a']--;
        bool f=true;
        for(ll i=0;i<26;i++)
            if(cnt[i]<0) {puts("0"); f=false; break;}
        if(!f) continue;
        ll ans=1,sum=0;
        for(ll i=0;i<26;i++)
        {
            sum+=cnt[i];
            ans=1LL*ans*invf[cnt[i]]%MOD;
        }
        ans=1LL*ans*fact[sum]%MOD;
        ans=1LL*ans*((int)s.size()-(int)t.size()+1)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}

