/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-12 11:11:45
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
ll C,Hr,Hb,Wr,Wb;
int main()
{
    scanf("%lld%lld%lld%lld%lld",&C,&Hr,&Hb,&Wr,&Wb);
    if(C/Wr<=10000000||C/Wb<=10000000)
    {
        if(C/Wb<=10000000)
        {
            swap(Wr,Wb);
            swap(Hr,Hb);
        }
        ll ans=0;
        for(ll i=0;i*Wr<=C;i++)
            ans=max(ans,i*Hr+(C-i*Wr)/Wb*Hb);
        printf("%lld\n",ans);
        return 0;
    }
    if(Hr*Wb==Hb*Wr)
    {
        ll res=__gcd(Wr,Wb);
        ll ans=(C-C%res)*Hr/Wr;
        printf("%lld\n",ans);
        return 0;
    }
    if(Hr*Wb<Hb*Wr)
    {
        swap(Wr,Wb);
        swap(Hr,Hb);
    }
    ll ans=0;
    for(ll i=0;i<Wr;i++)
        ans=max(ans,i*Hb+(C-i*Wb)/Wr*Hr);
    printf("%lld\n",ans);
    return 0;
}

