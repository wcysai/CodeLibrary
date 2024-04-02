#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],sz[MAXN],dep[MAXN],p[MAXN];
ll k;
vector<int> G[MAXN];
void dfs(int v,int p){
    sz[v]=1; 
    for(auto to:G[v]){
        if(to==p) continue;
        dep[to]=dep[v]+1;
        dfs(to,v); sz[v]+=sz[to];
    }
}
bool cmp1(int u,int v) {return sz[u]>sz[v];}
bool cmp2(int u,int v) {return dep[u]>dep[v];}
int main(){
    scanf("%d%lld",&n,&k);
    for(int i=0;i<n-1;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(1,0);
    ll sum=0;
    for(int i=1;i<=n;i++) sum+=sz[i];
    if(k>sum||k<n) {puts("No"); return 0;}
    puts("Yes");
    vector<int> v,v2,v3;
    k=sum-k;
    for(int i=2;i<=n;i++) v.push_back(i);
    sort(v.begin(),v.end(),cmp1);
    v3.push_back(1);
    for(int i=0;i<(int)v.size();i++){
        if(k>=sz[v[i]]){
            v2.push_back(v[i]);
            k-=sz[v[i]];
        }
        else v3.push_back(v[i]);
    }
    sort(v2.begin(),v2.end(),cmp2); sort(v3.begin(),v3.end(),cmp2); reverse(v3.begin(),v3.end());
    int now=1;
    for(auto x:v2) p[x]=now++;
    for(auto x:v3) p[x]=now++;
    for(int i=1;i<=n;i++) printf("%d%c",p[i],i==n?'\n':' ');
    return 0;
}

