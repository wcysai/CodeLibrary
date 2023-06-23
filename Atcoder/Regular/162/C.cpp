#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,p[MAXN],a[MAXN];
vector<int> G[MAXN],sub[MAXN];
int cnt[MAXN];
void dfs(int v){
    for(auto to:G[v]){
        dfs(to);
        for(auto x:sub[to]) sub[v].push_back(x);
    }
    sub[v].push_back(a[v]);
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) G[i].clear(),sub[i].clear();
        for(int i=2;i<=n;i++) {scanf("%d",&p[i]); G[p[i]].push_back(i);}
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        dfs(1);
        bool f=false;
        for(int i=1;i<=n;i++){
            int empt=0;
            for(auto x:sub[i]) if(x==-1) empt++; else cnt[x]++;
            int need=0;
            for(int i=0;i<k;i++) if(!cnt[i]) need++;
            if(!cnt[k]&&(empt<=1)&&(need<=empt)) f=true; 
            for(auto x:sub[i]) if(x==-1) empt--; else cnt[x]--;
        }
        if(f) puts("Alice"); else puts("Bob");
    }
    return 0;
}

