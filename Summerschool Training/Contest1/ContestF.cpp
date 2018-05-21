#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
using namespace std;
typedef long long ll;
int p[MAXN],r[MAXN],cnt[MAXN],cira[MAXN],cirb[MAXN];
int n,m;
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
        cnt[i]=1;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) {p[x]=y; cnt[y]+=cnt[x];}
    else
    {
        p[y]=x;
        cnt[x]+=cnt[y];
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    int p=0;
    while(scanf("%d %d",&n,&m)==2)
    {
    p++;
    init(n);
    memset(cira,0,sizeof(cira));
    memset(cirb,0,sizeof(cirb));
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        unite(x,i);
    }
    for(int i=0;i<n;i++)
    {
        if(i==find(i)) cira[cnt[i]]++;
    }
    init(m);
    for(int i=0;i<m;i++)
    {
        int x;
        scanf("%d",&x);
        unite(x,i);
    }
    printf("Case #%d: ",p);
    for(int i=0;i<m;i++)
    {
        if(i==find(i)) cirb[cnt[i]]++;
    }
    ll s=1;
    for(int i=1;i<=n;i++)
    {
        if(cira[i]!=0)
        {
            ll t=0;
            for(int j=1;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    t=(t+cirb[j]*j)%MOD;
                    if(j*j!=i)  t=(t+cirb[i/j]*(i/j))%MOD;
                }
            }
            for(int j=0;j<cira[i];j++)
              s=s*t%MOD;
        }
    }
    printf("%I64d\n",s);
    }
    return 0;
}
