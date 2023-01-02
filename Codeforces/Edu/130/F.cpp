#include<bits/stdc++.h>
#define MAXN 400005
using namespace std;
int t,n,m,k;
vector<int> G[MAXN];
vector<int> rG[MAXN];
vector<int> vs;
bool used[MAXN];
int cmp[MAXN];
int ans[MAXN];
void add_edge(int from,int to)
{
    G[from].push_back(to);
    rG[to].push_back(from);
}
void dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
        if(!used[G[v][i]]) dfs(G[v][i]);
    vs.push_back(v);
}
void rdfs(int v,int k)
{
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<(int)rG[v].size();i++)
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
}
int scc()
{
    vs.clear();
    int V=2*n*k-1;
    for(int v=0;v<=V;v++) used[v]=false;
    for(int v=0;v<=V;v++) if(!used[v]) dfs(v);
    int k=0;
    for(int v=0;v<=V;v++) used[v]=false;
    for(int i=vs.size()-1;i>=0;i--) if(!used[vs[i]]) rdfs(vs[i],k++);
    return k;
}
int id(int i,int j){
    return (i-1)*k+j-1;
}
void must(int id){
    add_edge(2*id+1,2*id);
}
void mustnt(int id){
    add_edge(2*id,2*id+1);
}
void implies(int x,int y){
    add_edge(2*x,2*y);
    add_edge(2*y+1,2*x+1);
}
void impliesnot(int x,int y){
    add_edge(2*x,2*y+1);
    add_edge(2*y,2*x+1);
}
void either(int x,int y){
    add_edge(2*x,2*y+1);
    add_edge(2*y,2*x+1);
    add_edge(2*x+1,2*y);
    add_edge(2*y+1,2*x);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<=20*n;i++) {G[i].clear(); rG[i].clear();}
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k-1;j++){
                implies(id(i,j+1),id(i,j));
            }
            if(i!=n)
            {
                for(int j=1;j<=k;j++) implies(id(i,j),id(i+1,j));
            }
            must(id(i,1));
        }
        for(int z=1;z<=m;z++){
            int type,i,j,x;
            scanf("%d%d",&type,&i);
            if(type==1){
                scanf("%d",&x);
                if(x==k) mustnt(id(i,k)); else implies(id(i,x),id(i,x+1));
            }
            else{
                scanf("%d%d",&j,&x);
                if(type==2){
                    for(int l=1;l<=k;l++){
                        if(l>x){
                            if(l==k) mustnt(id(i,l)); else implies(id(i,l),id(i,l+1));
                            if(l==k) mustnt(id(j,l)); else implies(id(j,l),id(j,l+1));
                        }
                        else if(x-l+1>=1&&x-l+1<=k){
                            impliesnot(id(i,l),id(j,x-l+1));
                            impliesnot(id(j,l),id(i,x-l+1));
                        }
                    }
                }
                else{
                    for(int l=1;l<=k;l++){
                        if(x-l>k){
                            if(l==k) mustnt(id(i,l)); else implies(id(i,l),id(i,l+1));
                            if(l==k) mustnt(id(j,l)); else implies(id(j,l),id(j,l+1));
                        }
                        else if(x-l+1>=1&&x-l+1<=k){
                            add_edge(2*id(i,l)+1,2*id(j,x-l+1)); add_edge(2*id(j,x-l+1)+1,2*id(i,l));
                            add_edge(2*id(j,l)+1,2*id(i,x-l+1)); add_edge(2*id(i,x-l+1)+1,2*id(j,l));
                        }
                    }
                }
            }
        }
        bool f=true;
        int num=scc();
        for(int i=0;i<n*k;i++){
            if(cmp[2*i]==cmp[2*i+1]){
                f=false;
                break;
            }
        }
        if(!f) {puts("-1"); continue;}
        for(int i=1;i<=n;i++) ans[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                int x=id(i,j);
                if(cmp[2*x]>cmp[2*x+1]) ans[i]=max(ans[i],j);
            }
        }
        for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}

