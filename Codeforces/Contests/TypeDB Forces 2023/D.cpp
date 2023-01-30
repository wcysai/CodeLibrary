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
int t,n,k,a[MAXN];
bool bad[MAXN];
int vis[MAXN];
int tot,id[MAXN],c;
vector<int> rG[MAXN];
int cc[MAXN];
void dfs(int v){
    cc[v]=1;
    for(auto to:rG[v]){
        dfs(to); cc[v]+=cc[to];
    }
}
int main()
{
    scanf("%d",&t);
    while(t--){
        tot=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) rG[i].clear();
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++) if(i+a[i]>=1&&i+a[i]<=n) rG[i+a[i]].push_back(i);
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                ++tot;
                vector<int> tmp; tmp.push_back(i);
                int now=i;
                bool f=true;
                while(f){
                    vis[now]=tot;
                    now+=a[now];
                    if(now<1||now>n){
                        for(auto x:tmp) bad[x]=false;
                        f=false;
                    }
                    else if(vis[now]==tot){
                        for(auto x:tmp) {bad[x]=true; cnt++;}
                        f=false;
                    }
                    else if(vis[now]>0&&vis[now]<tot){
                        if(bad[now]) 
                        {
                            for(auto x:tmp) {bad[x]=true; cnt++;}
                        }
                        else{
                            for(auto x:tmp) {bad[x]=false; }
                        }
                        f=false;
                    }
                    else tmp.push_back(now);
                }
            }
        }
        for(int i=1;i<=n;i++) vis[i]=0,id[i]=0;
        ll ans=0;
        if(bad[1]){
            vector<int> tmp;
            bool f=true; int now=1;
            while(f){
                vis[now]=1; tmp.push_back(now);
                now+=a[now]; if(vis[now]) break;
            }
            int sz=(int)tmp.size();
            ans=1LL*sz*(2*n+1-cnt);
        }
        else{
            vector<int> tmp;
            bool f=true; int now=1;
            while(f){
                vis[now]=true; tmp.push_back(now);
                now+=a[now]; if(now<1||now>n) break;
            }
            int sz=(int)tmp.size();
            dfs((int)tmp.back());
            ans=1LL*n*(2*n+1)-1LL*sz*cnt;
            for(auto x:tmp) ans-=cc[x];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

