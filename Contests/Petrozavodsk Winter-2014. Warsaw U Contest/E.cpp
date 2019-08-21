#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXM 500005
#define INF 1000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll tri[MAXN];
int tot;
ll K;
bool is_triangular(ll x)
{
    int res=(int)sqrt(2*x);
    for(int i=min(1,res-10);i<=res+10;i++) if(1LL*i*(i+1)/2==x) return true;
    return false;
}
int solve(ll x)
{
    int a=x%6,b=0;
    ll res=x/6;
    if(res==0) return a;
    if(is_triangular(res)) b=1;
    else
    {
        int l=1,r=tot;
        while(l<=r)
        {
            if(tri[l]+tri[r]==res) {b=2; break;}
            if(tri[l]+tri[r]<res) l++; else r--;
        }
        if(!b) b=3;
    }
    return (a>=b?a:a+6);
}
int main()
{
    for(int i=1;;i++)
    {
        tri[++tot]=1LL*i*(i+1)/2;
        if(6*tri[tot]>=INF) break;
    }
    while(scanf("%lld",&K)==1)
    {
        if(!K) break;
        printf("%d\n",solve(K));
    }
    return 0;
}
