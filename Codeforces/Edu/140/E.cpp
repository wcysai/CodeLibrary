#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define MAXM 45
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int c[MAXM],x[MAXM];
bool con[MAXM][MAXM];
bool rem[MAXM];
int deg[MAXM];
ll res;
void remove(int v)
{
    deg[v]=0;
    for(int i=0;i<m;i++)
        if(con[v][i]&&!rem[i])
            deg[i]--;
    rem[v]=true;
}
void recover(int v)
{
    for(int i=0;i<m;i++)
        if(con[v][i]&&!rem[i])
            {deg[v]++; deg[i]++;}
    rem[v]=false;
}
void dfs(ll cur)
{
    if(cur>res) return;
    int id=-1;
    for(int i=0;i<m;i++)
        if(id==-1||deg[i]>deg[id]) id=i;
    if(!deg[id]) {res=min(res,cur); return;}
    //remove id
    remove(id); dfs(cur+x[id]); recover(id);
    //remove all neighbours
    vector<int> nb;
    for(int i=0;i<m;i++)
        if(con[id][i]&&!rem[i])
            nb.push_back(i);
    for(auto y:nb) {remove(y); cur+=x[y];}
    dfs(cur);
    for(auto y:nb) recover(y); 
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {scanf("%d",&c[i]); c[i]--;}
    for(int i=0;i<m;i++) scanf("%d",&x[i]);
    ll cost=0,mus=0;
    mus|=(1LL<<c[1]); mus|=(1LL<<c[n]);
    for(int i=1;i<=n-1;i++) if(c[i]==c[i+1]) mus|=(1LL<<c[i]);
    for(int i=0;i<m;i++) if(mus&(1LL<<i)) cost+=x[i];
    for(int i=1;i<=n-1;i++)
    {
        if(mus&(1LL<<c[i])) continue;
        if(mus&(1LL<<c[i+1])) continue;
        if(c[i]==c[i+1]) continue;
        if(!con[c[i]][c[i+1]]) {deg[c[i]]++; deg[c[i+1]]++;}
        con[c[i]][c[i+1]]=con[c[i+1]][c[i]]=true;
    }
    res=INF;
    memset(rem,false,sizeof(rem));
    dfs(0);
    printf("%lld\n",cost+res);
    return 0;
}

