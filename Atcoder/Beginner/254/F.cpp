#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,k,a[MAXN],b[MAXN];
int da[18][MAXN],db[18][MAXN],pre[MAXN];
void init()
{
    pre[1]=0;
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if((1<<pre[i]+1)==i) ++pre[i];
    }
}
int solve(int da[18][MAXN],int l,int r)
{
    if(l>r) return 0;
    int len=r-l+1; k=pre[len];
    return __gcd(da[k][l],da[k][r-(1<<k)+1]);
}
int main()
{
    scanf("%d%d",&n,&q);
    init();
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n-1;i++) da[0][i]=max(a[i+1]-a[i],a[i]-a[i+1]);
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j+(1<<i)-1<=n-1;j++)
            da[i][j]=__gcd(da[i-1][j],da[i-1][j+(1<<(i-1))]);
    for(int i=1;i<=n-1;i++) db[0][i]=max(b[i+1]-b[i],b[i]-b[i+1]);
    for(int i=1;(1<<i)<=n;i++)
        for(int j=1;j+(1<<i)-1<=n-1;j++)
            db[i][j]=__gcd(db[i-1][j],db[i-1][j+(1<<(i-1))]);
    for(int i=0;i<q;i++)
    {
        int h1,h2,w1,w2;
        scanf("%d%d%d%d",&h1,&h2,&w1,&w2);
        int g=solve(da,h1,h2-1); 
        g=__gcd(g,solve(db,w1,w2-1));
        g=__gcd(g,a[h1]+b[w1]);
        printf("%d\n",g);
    }
    return 0;
}

