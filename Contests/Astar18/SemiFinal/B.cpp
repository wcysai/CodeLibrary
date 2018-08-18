/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-18 14:54:58
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
int T,n,k,l[MAXN],r[MAXN];
int _mod(int x) {return x>=MOD?x-MOD:x;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int find(int x)
{
    int p=1,sum;
    for(int i=1;i<=n;i++) 
    {
        if(x<=r[i]) sum=(x-l[i]+2)*(x-l[i]+1)/2;
        else sum=(x-l[i]+x-r[i]+2)*(r[i]-l[i]+1)/2;
        p=1LL*p*sum%MOD;
    }
    return p;
}
int find2(int x)
{
    int p=1,sum;
    for(int i=1;i<=n;i++) 
    {
        if(x<=r[i]) sum=(x-l[i]+3)*(x-l[i])/2;
        else sum=(x-l[i]+x-r[i]+2)*(r[i]-l[i]+1)/2;
        p=1LL*p*sum%MOD;
    }
    return p;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int mx=-INF,minx=-INF;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d%d",&l[i],&r[i]);
            mx=max(mx,l[i]);
            minx=max(minx,r[i]);
        }
        int ans=0;
        for(int i=mx;i<=minx;i++) 
        {
            ans=_mod(ans+find(i));
            ans-=find2(i);
            if(ans<0) ans+=MOD;
            //printf("%d\n",ans);
        }
        int p=1;
        for(int i=1;i<=n;i++) p=1LL*p*(r[i]-l[i]+1)%MOD;
        ans=1LL*ans*pow_mod(p,MOD-2)%MOD;
        printf("%d\n",ans);
    }
    return 0;
}

