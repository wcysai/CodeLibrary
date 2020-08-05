#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,M;
int treecnt[MAXN],treesum[MAXN],forestcnt[MAXN],forestsum[MAXN];
int p[MAXN][MAXN],comb[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=M) a-=M;}
void dec(int &a,int b) {a-=b; if(a<0) a+=M;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%M;
        a=1LL*a*a%M;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d%d",&T,&M);
    comb[0][0]=1;
    for(int i=1;i<=5000;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++)
        {
            comb[i][j]=comb[i-1][j-1];
            add(comb[i][j],comb[i-1][j]);
        }
    }
    for(int i=1;i<=5000;i++)
    {
        p[i][0]=1;
        for(int j=1;j<=5000;j++) p[i][j]=1LL*p[i][j-1]*i%M;
    }
    treecnt[0]=treecnt[1]=1;
    for(int i=2;i<=5000;i++) treecnt[i]=p[i][i-2];
    treesum[1]=0;
    for(int i=2;i<=5000;i++)
    {
        for(int deg=1;deg<=i-1;deg++) add(treesum[i],1LL*comb[i-2][deg-1]*p[i-1][i-2-(deg-1)]%M*deg%M*deg%M);
        treesum[i]=1LL*treesum[i]*i%M;
    }
    forestcnt[0]=1;
    for(int i=1;i<=5000;i++)
        for(int j=1;j<=i;j++)
            add(forestcnt[i],1LL*treecnt[j]*comb[i-1][j-1]%M*forestcnt[i-j]%M);
    for(int i=1;i<=5000;i++)
    {
        for(int j=1;j<=i;j++)
        {
            add(forestsum[i],1LL*treesum[j]*comb[i-1][j-1]%M*forestcnt[i-j]%M);
            add(forestsum[i],1LL*treecnt[j]*comb[i-1][j-1]%M*forestsum[i-j]%M);
        }
    }
    while(T--)
    {
        scanf("%d",&N);
        printf("%d\n",forestsum[N]);
    }
    return 0;
}