/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-26 20:09:01
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN],ans;
int main()
{
    scanf("%lld",&n);
    ans=0;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    ll st=1,ed=1,now=0;
    do
    {
        while(ed<=n&&(now+a[ed])==(now^a[ed]))
        {
            now+=a[ed];
            ed++;
        }
        ans+=ed-st;
        //printf("%lld %lld %lld\n",st,ed,now);
        now-=a[st];
        st++;
    }while(st<=n);
    printf("%lld\n",ans);
    return 0;
}

