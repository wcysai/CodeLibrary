#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int p2[MAXN];
vector<int> v[MAXN];
int id[MAXN];
vector<P> G[MAXN];
vector<pair<P,int> > cons;
int color[MAXN];
int p[MAXN],r[MAXN];
void add_edge(int u,int v,int c){
    G[v].push_back(P(u,c));
    G[u].push_back(P(v,c));
}
void init(int n){
    for(int i=1;i<=n;i++){
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
int cc=0;
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    cc++;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int state[MAXN];
bool col[MAXN];
queue<int> que;
set<int> s;
bool check(){
    vector<int> v1,v2;
    for(int i=1;i<=n;i++){
        if(col[a[i]]) v1.push_back(a[i]); else v2.push_back(a[i]);
        col[a[i]]=!col[a[i]];
    }
    return v1==v2;
}
int main()
{
    p2[0]=1;
    for(int i=1;i<=200000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        id[i]=(int)v[a[i]].size();
        v[a[i]].push_back(i);
    }
    bool f=true;
    int cnt=0,m=0;
    for(int i=1;i<=200000;i++) {
        if(v[i].size()&1) f=false;
        if(v[i].size()) cnt++;
    }
    if(!check()) f=false;
    if(!f) {printf("%d\n",p2[cnt-1]); return 0;}
    for(int i=1;i<=n;i++) s.insert(i);
    init(200000);
    for(int x=1;x<=200000;x++){
        for(int i=0;i<(int)v[x].size();i+=2){
            int l=v[x][i]+1,r=v[x][i+1]-1;
            auto it=s.lower_bound(l);
                //printf("l=%d r=%d\n",l,r);
                while(it!=s.end()&&(*it<=r)){
                    //printf("*it=%d\n",*it);
                    if(!col[a[*it]]) unite(x,a[*it]); 
                    it=s.erase(it);
                }
            }
    }
    if(!f) {printf("%d\n",p2[cnt-1]); return 0;}
    int ans=p2[cnt-1]; dec(ans,p2[cnt-cc-1]);
    printf("%d\n",ans);
    return 0;
}
