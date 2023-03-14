#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n;
int a[2][MAXN];
int ans;
vector<P> G[2*MAXN];
ll d[2][2*MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
void add_edge(int u,int v,int c){
    G[u].push_back(P(v,c));
}
void dijkstra(int id,int s,int l,int r)
{
    priority_queue<P,vector<P>,greater<P> > que;
    for(int i=l;i<=r;i++) d[id][i]=d[id][n+i]=INF;
    d[id][s]=(s<=n?a[0][s]:a[1][s-n]);
    que.push(P(d[id][s],s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        int v=p.S;
        if(d[id][v]<p.F) continue;
        for(int i=0;i<(int)G[v].size();i++)
        {
            P e=G[v][i];
            int x=(e.F>n?e.F-n:e.F);
            if(x<l||x>r) continue;
            if(d[id][e.F]>d[id][v]+e.S)
            {
                d[id][e.F]=d[id][v]+e.S;
                que.push(P(d[id][e.F],e.F));
            }
        }
    }
}

void solve(int l,int r){
    if(l>r) return;
    int mid=(l+r)/2;
    dijkstra(0,mid,l,r); dijkstra(1,mid+n,l,r);
    for(int i=l;i<=r;i++){
        add(ans,2LL*d[0][i]%MOD); add(ans,2LL*d[1][i]%MOD);
        add(ans,2LL*d[0][n+i]%MOD); add(ans,2LL*d[1][n+i]%MOD);
    }
    dec(ans,2LL*d[1][mid]%MOD); dec(ans,a[0][mid]%MOD); dec(ans,a[1][mid]%MOD);
    //printf("ans=%lld\n",ans);
    vector<P> v1,v2;
    vector<int> d1,d2;
    for(int i=l;i<mid;i++){
        v1.push_back(P(d[0][i]-a[0][mid],d[1][i]-a[1][mid])); d1.push_back(d[0][i]-d[1][i]-a[0][mid]+a[1][mid]);
        v1.push_back(P(d[0][n+i]-a[0][mid],d[1][n+i]-a[1][mid])); d1.push_back(d[0][n+i]-d[1][n+i]-a[0][mid]+a[1][mid]);
    }
    for(int i=mid+1;i<=r;i++){
        v2.push_back(P(d[0][i],d[1][i])); d2.push_back(d[1][i]-d[0][i]);
        v2.push_back(P(d[0][n+i],d[1][n+i])); d2.push_back(d[1][n+i]-d[0][n+i]);
    }
    sort(d1.begin(),d1.end()); sort(d2.begin(),d2.end());
    for(auto p:v1){
        //printf("v1 p.F=%d p.S=%d\n",p.F,p.S);
        ll dif=p.F-p.S;
        int num=lower_bound(d2.begin(),d2.end(),dif)-d2.begin();
        add(ans,2LL*num*(p.S%MOD)%MOD);
        add(ans,2LL*((int)d2.size()-num)*(p.F%MOD)%MOD);
        //printf("num=%d\n",num);
    }
    for(auto p:v2){
        //printf("v2 p.F=%d p.S=%d\n",p.F,p.S);
        ll dif=p.S-p.F;
        int num=lower_bound(d1.begin(),d1.end(),dif+1)-d1.begin();
        add(ans,2LL*num*(p.F%MOD)%MOD);
        add(ans,2LL*((int)d1.size()-num)*(p.S%MOD)%MOD);
        //printf("num=%d\n",num);
    }
    //printf("ans=%lld\n",ans);
    solve(l,mid-1); solve(mid+1,r);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<2;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            if(j>1) 
            {
                add_edge(i*n+j,i*n+j-1,a[i][j-1]);
                add_edge(i*n+j-1,i*n+j,a[i][j]);
            }
            if(i){
                add_edge(i*n+j,(i-1)*n+j,a[i-1][j]);
                add_edge((i-1)*n+j,i*n+j,a[i][j]);
            }
        }
    solve(1,n);
    printf("%lld\n",ans);
    return 0;
}

