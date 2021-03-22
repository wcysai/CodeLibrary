#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,c[MAXN][MAXN];
ll a[MAXN],b[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&c[i][j]);
    a[1]=0; b[1]=c[1][1];
    bool f=true;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            if(c[i][j]-c[i-1][j]!=c[i][1]-c[i-1][1])
            {
                f=false;
                break;
            }
        }
        a[i]=a[i-1]+(c[i][1]-c[i-1][1]);
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            if(c[j][i]-c[j][i-1]!=c[1][i]-c[1][i-1])
            {
                f=false;
                break;
            }
        }
        b[i]=b[i-1]+(c[1][i]-c[1][i-1]);
    }
    if(!f) puts("No");
    else
    {
        ll x=INF,y=INF;
        for(int i=1;i<=n;i++) x=min(x,a[i]);
        for(int i=1;i<=n;i++) y=min(y,b[i]);
        if(x+y<0) {puts("No"); return 0;}
        puts("Yes");
        if(x<0)
        {
            for(int i=1;i<=n;i++) a[i]-=x;
            for(int i=1;i<=n;i++) b[i]+=x;
        }
        if(y<0)
        {
            for(int i=1;i<=n;i++) a[i]+=y;
            for(int i=1;i<=n;i++) b[i]-=y;
        }
        for(int i=1;i<=n;i++) printf("%lld%c",a[i],i==n?'\n':' ');
        for(int i=1;i<=n;i++) printf("%lld%c",b[i],i==n?'\n':' ');
    }
    return 0;
}