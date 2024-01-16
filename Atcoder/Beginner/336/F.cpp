#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 8
#define MAXM 1200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int,int> P;
int n,m,tot,tot_id,a[MAXN][MAXN]; 
vector<int> v;
map<vector<int>,int> mp;
vector<int> save[MAXM];
int dist[MAXM];
int get_id(vector<int> &v){
    if(mp.find(v)==mp.end()) {mp[v]=++tot; save[tot]=v;}
    return mp[v];
}
void rot(int x,int y,mat &a){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<m-1;j++){
            if(x+i<x+n-2-(i)||(x+i<=x+n-2-(i)&&y+j<y+m-2-(j))){
                swap(a[x+i][y+j],a[x+n-2-(i)][y+m-2-(j)]);
            }
        }
}
void bfs(){
    vector<int> v;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            v.push_back(i*m+j);
    mp[v]=1; save[1]=v; tot=1;
    memset(dist,-1,sizeof(dist));
    queue<int> que;
    que.push(1); dist[1]=0;
    while(que.size()){
        int v=que.front(); que.pop();
        if(dist[v]==10) break;
        mat vv(n,vec(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                vv[i][j]=save[v][i*m+j];
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++){
                rot(i,j,vv);
                vector<int> tmp;
                for(int k=0;k<n;k++)
                    for(int l=0;l<m;l++)
                        tmp.push_back(vv[k][l]);
                int id=get_id(tmp);
                if(dist[id]==-1) {dist[id]=dist[v]+1; que.push(id);}
                rot(i,j,vv);
            }
    }
}
int main(){
    tot=0;
    scanf("%d%d",&n,&m);
    vector<int> v;
    vector<int> pos(n*m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            int x;
            scanf("%d",&x); x--;
            v.push_back(x);
            pos[x]=i*m+j;
        }
    bfs();
    int ans=21;
    for(int i=1;i<=tot;i++){
        vector<int> pos2(n*m),tmp(n*m);
        for(int j=0;j<n*m;j++) pos2[save[i][j]]=j;
        for(int j=0;j<n*m;j++) tmp[pos[j]]=pos2[j];
        if(mp.find(tmp)!=mp.end()) ans=min(ans,dist[i]+dist[mp[tmp]]); 
    }
    if(ans==21) printf("-1\n"); else printf("%d\n",ans);
    return 0;
}

