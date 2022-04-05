/*************************************************************************
    > File Name: MINDSUM.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-07 03:52:51
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
typedef pair<ll,ll> P;
ll T,N,D;
ll sum(ll x)
{
    ll s=0;
    while(x)
    {
        s+=x%10;
        x/=10;
    }
    return s;
}
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&N,&D);
        ll d=D%9,targ;
        if(d%3!=0) targ=1; else if(d==0) targ=N%9; else {targ=N%3; if(targ==0) targ=3;}
        queue<P> que;
        que.push(P(N,0));
        while(!que.empty())
        {
            P p=que.front();que.pop();
            if(p.F==targ) {printf("%lld %lld\n",targ,p.S); break;}
            ll nxt1=p.F+D,nxt2=sum(p.F);
            que.push(P(nxt1,p.S+1));que.push(P(nxt2,p.S+1));
        }
    }
    return 0;
}

