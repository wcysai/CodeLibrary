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
int n,a[MAXN],b[MAXN],ans[MAXN],f[MAXN];
ll k;
int vis[MAXN];
int id[MAXN],depth[MAXN];
int st[19][MAXN];
vector<int> rG[MAXN];
int alladd;
int acc[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int tot;
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void dfs(int v){
    for(auto to:rG[v]){
        if(id[to]) continue;
        dfs(to);
        add(ans[v],ans[to]);
    }
}
int get(int v,int len){
    for(int i=18;i>=0;i--){
        if(len&(1<<i)) v=st[i][v];
    }
    return v;
}
void solve(int v){
    //printf("v=%d\n",v);
    alladd=0;
    vector<int> tmp;
    while(!vis[v]){
        tmp.push_back(v);
        vis[v]=++tot;
        v=a[v];
    }
    int len=(tot+1)-vis[v];
    for(auto x:tmp) vis[x]=0;
    vector<int> cyc;
    for(int i=0;i<len;i++){
        cyc.push_back(tmp.back());
        tmp.pop_back();
    }
    for(int i=0;i<=len;i++) acc[i]=0;
    reverse(cyc.begin(),cyc.end());
    for(int i=0;i<(int)cyc.size();i++) id[cyc[i]]=i+1;
    vector<int> all; queue<int> que;
    for(auto x:cyc){
        que.push(x); depth[x]=0;
        all.push_back(x); vis[x]=1;
    }
  //  for(auto x:cyc) printf("%d ",x);
  //  printf("\n");
    while(que.size()){
        int x=que.front(); que.pop();
        for(auto to:rG[x]){
            if(id[to]) continue; depth[to]=depth[x]+1;
            vis[to]=1; all.push_back(to); que.push(to);
        }
    }
    for(auto x:all){
    //    printf("x=%d depth=%d\n",x,depth[x]);
        if(depth[x]>k){
            int anc=get(x,k+1);
      //      printf("anc=%d\n",anc);
            add(ans[a[x]],b[x]); dec(ans[anc],b[x]);
        }
        else{
            int val=b[x];
            x=a[x];
            int anc=get(x,depth[x]);
        //    printf("anc=%d\n",anc);
            add(ans[x],val); dec(ans[anc],val);
            int st=id[anc]-1; ll rem=k-1-depth[x];
            add(alladd,1LL*((rem/len)%MOD)*val%MOD);
            int remi=rem%len;
            int l=st,r=(st+remi)%len;
            if(l>r) add(alladd,val);
            add(acc[l],val);
            dec(acc[r+1],val);
        }
    }
    for(auto x:cyc) dfs(x);
    for(int i=1;i<=len;i++) add(acc[i],acc[i-1]);
    for(auto x:cyc) {ans[x]=acc[id[x]-1]; add(ans[x],alladd);}
}   
int main()
{
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); rG[a[i]].push_back(i);}
    for(int i=1;i<=n;i++) st[0][i]=a[i];
    for(int i=1;i<=18;i++)
        for(int j=1;j<=n;j++) 
            st[i][j]=st[i-1][st[i-1][j]];
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++){
        if(!vis[i]) solve(i);
    }
    int res=pow_mod((k%MOD),MOD-2);
    for(int i=1;i<=n;i++) ans[i]=1LL*ans[i]*res%MOD;
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}

