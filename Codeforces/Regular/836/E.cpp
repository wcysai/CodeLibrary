#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,h;
int p[MAXN];
int sum[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        sum[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return p[x];
    int y=find(p[x]);
    sum[x]+=sum[p[x]]; sum[x]%=h;
    p[x]=y;
    return y;
}
bool unite(int u,int v,ll z)
{
    int x=find(u);
    int y=find(v);
    if(x==y)
    {
        if(sum[u]==(sum[v]+z)%h) return true;
        else return false;
    }
    int shift=(z-sum[u]+sum[v])%h;
    if(shift<0) shift+=h;
    p[x]=y;
    sum[x]+=shift; sum[x]%=h;
    return true;
}
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
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&h);
        mat a(n,vec(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        init(n);
        int cnt=0;
        bool f=true;
        for(int i=0;i<m;i++)
        {
            int last=-1;
            for(int j=0;j<n;j++)
            {
                if(a[j][i]!=-1)
                {
                    if(last!=-1)
                    {
                        if(!unite(last+1,j+1,(a[last][i]-a[j][i]+h)%h)) f=false;
                    }
                    last=j;
                }
            }
            if(last!=-1) cnt++;
        }
        if(!f) {puts("0"); continue;}
        int fr=n+m-1-cnt;
        for(int i=1;i<=n;i++) if(find(i)!=i) fr--;
        printf("%d\n",pow_mod(h,fr));
    }
    return 0;
}

