#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXM 6000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,tot,a[MAXN];
int trie[MAXM][2],maxi[MAXM];
int st[MAXN],s[MAXN],t;
int ans,fa[MAXN],ls[MAXN],rs[MAXN],root;
vector<P> query[MAXN];
void ins(int x,int pos){
    int rt=0;
    maxi[rt]=max(maxi[rt],pos);
    for(int i=29;i>=0;i--){
        int v=(x>>i)&1;
        if(!trie[rt][v]) trie[rt][v]=++tot;
        rt=trie[rt][v];
        maxi[rt]=max(maxi[rt],pos);
    }
}
void go(int pos,int l,int r){
    if(!pos) return;
    if(pos-l<=r-pos){
        for(int i=l;i<=pos;i++){
            query[r].push_back(P(pos,s[i-1]^a[pos]));
        }
    }
    else{
        for(int i=pos;i<=r;i++){
            query[pos-1].push_back(P(l-1,s[i]^a[pos]));
        }
    }
    go(ls[pos],l,pos-1); go(rs[pos],pos+1,r);
}
int solve(int l,int val){
    int rt=0,res=0;
    for(int i=29;i>=0;i--){
        int v=(val>>i)&1;
        if(trie[rt][v^1]&&maxi[trie[rt][v^1]]>=l){
            rt=trie[rt][v^1]; res+=(1<<i);
        }
        else rt=trie[rt][v];
    }
    return res;
}
int main()
{
    memset(maxi,-1,sizeof(maxi));
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) ls[i]=rs[i]=fa[i]=0;
        for(int i=1;i<=n;i++) query[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
        t=0;
        for(int i=1;i<=n;i++){
            while(t&&a[st[t-1]]<a[i]) ls[i]=st[--t];
            if(t) rs[st[t-1]]=i;
            st[t++]=i;
        }
        for(int i=1;i<=n;i++) fa[ls[i]]=fa[rs[i]]=i;
        for(int i=1;i<=n;i++) if(!fa[i]) root=i;
        go(root,1,n);
        ans=0; tot=0;
        for(int i=0;i<=n;i++){
            ins(s[i],i);
            for(auto p:query[i]) ans=max(ans,solve(p.F,p.S));
        }
        printf("%d\n",ans);
        for(int i=0;i<=tot;i++) maxi[i]=-1,trie[i][0]=trie[i][1]=0;
    }
    return 0;
}

