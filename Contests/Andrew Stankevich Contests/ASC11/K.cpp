#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define x1 dkaid
#define y1 dksadai
#define x2 dksadoa
#define y2 doksakdoa
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,y,p,s;
int x1[MAXN],y1[MAXN],x2[MAXN],y2[MAXN],dep[MAXN];
double peri[MAXN],volume[MAXN],rate[MAXN],len;
vector<P> G[MAXN];
double ans;
bool done[MAXN];
int main()
{
    freopen("swimming.in","r",stdin);
    freopen("swimming.out","w",stdout);
    scanf("%d%d%d%d%d",&n,&x,&y,&p,&s);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i],&dep[i]);
        peri[i]=2*(y2[i]-y1[i]+x2[i]-x1[i]);
        volume[i]=10*(y2[i]-y1[i])*(x2[i]-x1[i])*dep[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(x1[i]==x2[j]||x2[i]==x1[j])
            {
                int l1=y1[i],r1=y2[i],l2=y1[j],r2=y2[j];
                int l=max(l1,l2),r=min(r1,r2);
                if(l<r) {G[i].push_back(P(j,r-l)); G[j].push_back(P(i,r-l));}
            }
            else if(y1[i]==y2[j]||y2[i]==y1[j])
            {
                int l1=x1[i],r1=x2[i],l2=x1[j],r2=x2[j];
                int l=max(l1,l2),r=min(r1,r2);
                if(l<r) {G[i].push_back(P(j,r-l)); G[j].push_back(P(i,r-l));}

            }
        }
    }
    memset(rate,0,sizeof(rate));
    memset(done,false,sizeof(done));
    len=peri[p]; ans+=(double)volume[p]/s; done[p]=true;
    for(auto x:G[p]) rate[x.F]+=x.S; volume[p]=0;
    while(true)
    {
        double mini=INF;
        int id=-1;
        for(int i=1;i<=n;i++)
        {
            if(done[i]) continue;
            if(rate[i]!=0&&volume[i]/s*len/rate[i]<mini)
            {
                mini=volume[i]/s*len/rate[i];
                id=i;
            }
        }
        if(id==-1) break;
        ans+=mini;
        done[id]=true;
        for(int i=1;i<=n;i++)
        {
            if(done[i]) continue;
            volume[i]-=(double)s/len*rate[i]*mini;
        }
        len+=peri[id]-2*rate[id];
        rate[id]=0;
        for(auto x:G[id])
        {
            if(done[x.F]) continue;
            rate[x.F]+=x.S;
        }
    }
    printf("%.15f\n",ans);
    return 0;
}
