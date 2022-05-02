#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5025
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int f[MAXN],nf[MAXN],g[MAXN],ng[MAXN],sumf[MAXN],sumg[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        f[0]=1; g[0]=0;
        for(int i=1;i<=n;i++)
        {
            memset(nf,0,sizeof(nf));
            memset(ng,0,sizeof(ng));
            sumf[0]=f[0]; sumg[0]=g[0];
            for(int j=1;j<=5000;j++)
            {
                sumf[j]=sumf[j-1]; add(sumf[j],f[j]);
                sumg[j]=sumg[j-1]; add(sumg[j],g[j]);
            }
            for(int j=0;j<=10000;j++)
            {
                int l=min(5000,max(0,j-a[i])),r=min(j,5000);
                if(l<=r)
                {
                    add(nf[j/2],sumf[r]); dec(nf[j/2],l==0?0:sumf[l-1]);
                    add(ng[j/2],sumg[r]); dec(ng[j/2],l==0?0:sumg[l-1]);
                }
                if((j&1)&&j<=a[i])
                {
                    dec(nf[j/2],f[0]); dec(ng[j/2],g[0]);
                    add(nf[j/2+1],f[0]); add(ng[j/2+1],g[0]);
                    add(ng[j/2+1],f[0]);
                }
                //if(nf[j]||ng[j]) printf("%d %d %d %d\n",i,j,nf[j],ng[j]);
            }
            swap(f,nf); swap(g,ng);
        }
        int ans=0;
        for(int i=0;i<=5000;i++) add(ans,g[i]);
        printf("%d\n",ans);
    }
    return 0;
}

