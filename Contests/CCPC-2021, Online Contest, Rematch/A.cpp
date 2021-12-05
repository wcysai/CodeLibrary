#include<bits/stdc++.h>
#define MAXN 85
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,p[MAXN],ans[MAXN],a[MAXN];
int comb[MAXN][MAXN];
int cnt[MAXN],cntall[MAXN],fact[MAXN];
bool has[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    comb[0][0]=1;
    for(int i=1;i<=80;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(int j=1;j<i;j++) 
        {
            comb[i][j]=comb[i-1][j];
            add(comb[i][j],comb[i-1][j-1]);
        }
    }
    fact[0]=1;
    for(int i=1;i<=80;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnt[i]=cntall[i]=0;
        for(int i=2;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int c=0;
        for(int i=1;i<=n;i++) 
        {
            if(i==1||p[i]==1)
            {
                c++;
                if(a[i]) cnt[a[i]]++;
            }
            if(a[i]) cntall[a[i]]++;
        }
        for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1],cntall[i]+=cntall[i-1];
        for(int k=1;k<=n;k++)
        {
            ans[k]=0;
            int l=cnt[k-1],r=cnt[n]-cnt[k];
            printf("k=%d l=%d r=%d\n",k,l,r);
            if(cntall[k]&&!cnt[k]) continue;
            if(c&1)
            {
                int lneed=(c-1)/2-l,rneed=(c-1)/2-r;
                int lhas=(k-1)-cntall[k-1],rhas=(n-k)-(cntall[n]-cntall[k]);
                int pos1=c-cnt[n],pos2=n-cntall[n]-pos1;
                if(lhas>=lneed&&rhas>=rneed) add(ans[k],1LL*comb[lhas][lneed]*comb[rhas][rneed]%MOD*fact[pos1]%MOD*fact[pos2]%MOD);
            }
            else
            {
                int lneed=c/2-l,rneed=c/2-1-r;
                int lhas=(k-1)-cntall[k-1],rhas=(n-k)-(cntall[n]-cntall[k]);
                int pos1=c-cnt[n],pos2=n-cntall[n]-pos1;
                if(lhas>=lneed&&rhas>=rneed) add(ans[k],1LL*comb[lhas][lneed]*comb[rhas][rneed]%MOD*fact[pos1]%MOD*fact[pos2]%MOD);
                lneed=c/2-1-l,rneed=c/2-r;
                lhas=(k-1)-cntall[k-1],rhas=(n-k)-(cntall[n]-cntall[k]);
                pos1=c-cnt[n],pos2=n-cntall[n]-pos1;
                if(lhas>=lneed&&rhas>=rneed) add(ans[k],1LL*comb[lhas][lneed]*comb[rhas][rneed]%MOD*fact[pos1]%MOD*fact[pos2]%MOD);
            }
        }
        for(int k=1;k<=n;k++) printf("%d ",ans[k]);
        puts("");
    }
    return 0;
}