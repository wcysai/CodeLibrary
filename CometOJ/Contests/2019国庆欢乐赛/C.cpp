#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int lx[MAXN],ly[MAXN],rx[MAXN],ry[MAXN];
vector<int> dis;
int lcnt[MAXM],rcnt[MAXM];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&lx[i],&ly[i]);
        dis.push_back(lx[i]); dis.push_back(ly[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&rx[i],&ry[i]);
        dis.push_back(rx[i]); dis.push_back(ry[i]);
    }
    sort(dis.begin(),dis.end());
    dis.erase(unique(dis.begin(),dis.end()),dis.end());
    for(int i=1;i<=n;i++)
    {
        lx[i]=lower_bound(dis.begin(),dis.end(),lx[i])-dis.begin()+1;
        ly[i]=lower_bound(dis.begin(),dis.end(),ly[i])-dis.begin()+1;
    }
    for(int i=1;i<=m;i++)
    {
        rx[i]=lower_bound(dis.begin(),dis.end(),rx[i])-dis.begin()+1;
        ry[i]=lower_bound(dis.begin(),dis.end(),ry[i])-dis.begin()+1;
        lcnt[ry[i]]++; rcnt[rx[i]]++;
    }
    for(int i=1;i<=1000000;i++) lcnt[i]+=lcnt[i-1];
    for(int i=1000000;i>=0;i--) rcnt[i]+=rcnt[i+1];
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=m;
        ans-=lcnt[lx[i]-1];
        ans-=rcnt[ly[i]+1];
    }
    printf("%lld\n",ans);
    return 0;
}

