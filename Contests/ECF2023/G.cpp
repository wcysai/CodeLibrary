#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN][MAXN];
int p[MAXN];
void init(int n){
    for(int i=1;i<=n;i++) p[i]=i;
}
int find(int x){
    if(p[x]==x) return x;
    return p[x]=find(p[x]);
}
void unite(int x,int y){
    x=find(x); y=find(y);
    if(x==y) return;
    p[x]=y;
}
bool same(int x,int y){
    return find(x)==find(y);
}
vector<P> edges[4];
vector<P> ans;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ans.clear();
        for(int i=0;i<=3;i++) edges[i].clear();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                scanf("%d",&a[i][j]);
                if(i<j) edges[a[i][j]].push_back(P(i,j));
            }
        init(n);
        bool f=true;
        for(int i=3;i>=0;i--){
            if(!f) break;
            for(auto p:edges[i]){
                if(!f) break;
                if(same(p.F,p.S)) continue;
                unite(p.F,p.S); ans.push_back(p);
                for(int j=1;j<=n;j++){
                    if(same(j,p.F)) continue;
                    if(a[j][p.F]!=a[j][p.S]){ 
                        f=false; break;
                    }
                }
            }
        }
        if(!f) puts("No");
        else{
            puts("Yes");
            printf("%d\n",(int)ans.size());
            for(auto p:ans) printf("%d %d\n",p.F,p.S);
        }
    }
    return 0;
}

