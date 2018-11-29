/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-29 14:00:54
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
ll N,Q,k;
string str;
int main()
{
    scanf("%lld",&N);
    cin>>str;
    scanf("%lld",&Q);
    for(ll i=0;i<Q;i++)
    {
        scanf("%lld",&k);
        ll ans=0;
        ll d=0,m=0,cur=0;
        for(ll now=0;now<N;now++)
        {
            if(str[now]=='D') d++;
            else if(str[now]=='M') {cur+=d; m++;}
            else if(str[now]=='C')  ans+=cur;
            if(now+1>=k)
            {
                if(str[now+1-k]=='D') {cur-=m; d--;}
                else if(str[now+1-k]=='M') m--;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

