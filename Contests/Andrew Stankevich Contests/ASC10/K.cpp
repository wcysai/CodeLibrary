#include<bits/stdc++.h>
#define MAXN 25
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int m,n,t,l;
int I[MAXN],A[MAXN],L[MAXN],O[MAXN],T[MAXN],Z[MAXN],V[MAXN],C[MAXN];
int ans,bestmask;
int pen[MAXN],solved[MAXN];
int solve(int mask)
{
    memset(pen,0,sizeof(pen));
    memset(solved,0,sizeof(solved));
    for(int j=0;j<t;j++)
    {
        vector<P> cansolve; cansolve.clear();
        for(int i=0;i<m;i++)
        {
            if(!(mask&(1<<i))) continue;
            if(T[j]+C[j]<=I[i]-O[i]) continue;
            int exp=(I[i]+O[i]-1)/O[i]+max((A[i]+C[j]-1)/C[j],5);
            int act=max(I[i]-T[j],0)+(A[i]+Z[j]+C[j]-1)/(Z[j]+C[j])+(L[i]+V[j]-1)/V[j];
            cansolve.push_back(P(exp,act));
        }
        sort(cansolve.begin(),cansolve.end());
        int cnt=0;
        for(int i=0;i<(int)cansolve.size();i++)
        {
            cnt+=cansolve[i].S;
            if(cnt>l) break;
            solved[j]++;
            pen[j]+=cnt;
        }
    }
    int rk=1;
    for(int j=1;j<t;j++) 
    {
        if(solved[j]>solved[0]||(solved[j]==solved[0]&&pen[j]<pen[0])) rk++;
    }
    return rk;
}
int main()
{
    freopen("unfair.in","r",stdin);
    freopen("unfair.out","w",stdout);
    scanf("%d%d%d%d",&m,&n,&t,&l);
    for(int i=0;i<m;i++) scanf("%d%d%d%d",&I[i],&A[i],&L[i],&O[i]);
    for(int i=0;i<t;i++) scanf("%d%d%d%d",&T[i],&Z[i],&V[i],&C[i]);
    int comb=(1<<n)-1;
    ans=INF; bestmask=-1;
    while(comb<(1<<m))
    {
        if(solve(comb)<ans)
        {
            ans=solve(comb);
            bestmask=comb;
        }
        int x=comb&-comb,y=comb+x;
        comb=((comb&~y)/x>>1)|y;
    }
    for(int i=0;i<m;i++)
    {
        if(bestmask&(1<<i)) printf("%d ",i+1);
    }
    return 0;
}
