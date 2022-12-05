#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define int long long
#define y1 dsaokdos
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN];
int x1,y1,x2,y2;
int extgcd(int a,int b,int &x,int &y)
{
    int d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
        int a=x2-x1,b=y1-y2;
        if(a==0) {printf("%lld %lld\n",x1+1,y1); continue;}
        if(b==0) {printf("%lld %lld\n",x1,y1+1); continue;}
        bool rev=false;
        if(a<0) {a=-a; b=-b;}
        if(b<0) {rev=true; b=-b;}
        int x,y;
        extgcd(a,b,x,y);
        if(rev) {b=-b; y=-y;}
        printf("%lld %lld\n",x1+y,y1+x);
    }
    return 0;
}

