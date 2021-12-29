#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,m,a[MAXN],b[MAXN];
ll d[MAXN];
vector<P> va,vb;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        va.push_back(P((m-a[i])%m,i));
    }
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&b[i]);
        vb.push_back(P(b[i],i));
    }
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d+1,d+2*n+1,INF);
    d[1]=0;
    que.push(P(0,1));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.second;
        if(d[v]<p.first) continue;
        int pos=(v<=n?(m-a[v])%m:b[v-n]);
        //go to next b
        P q=P(pos,v>n?v-n+1:0);
        int id;
        if(vb.back()<q) id=0; else id=lower_bound(vb.begin(),vb.end(),q)-vb.begin();
        int cost=(vb[id].F-pos+m)%m;
        if(d[n+vb[id].S]>p.F+cost) 
        {
            d[n+vb[id].S]=p.F+cost;
            que.push(P(d[n+vb[id].S],n+vb[id].S));
        }
        if(v>n&&d[v-n]>d[v]) 
        {
            d[v-n]=d[v];
            que.push(P(d[v-n],v-n));
        } 
    }
    printf("%lld\n",d[2*n]);
    return 0;
}
