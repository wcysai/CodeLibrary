#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int x,y;
ll _sqr(ll x)
{
    ll l=1,r=1000001;
    while(r-l>1)
    {
        ll mid=(l+r)/2;
        if(mid*mid*mid<=x) l=mid; else r=mid;
    }
    return l;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        ll s=(ll)x*y;
        ll res=_sqr(s);
        if(res*res*res!=s||x%res!=0||y%res!=0) {puts("No"); continue;}
        ll xx=x/res,yy=y/res;
        if(xx*yy==res) puts("Yes"); else puts("No");
    }
    return 0;
}
