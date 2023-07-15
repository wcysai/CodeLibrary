#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,q,a[MAXN],p[MAXN];
int fa[MAXN],st[MAXN],t,ls[MAXN],rs[MAXN],maxi[MAXN],root;
vector<P> vec;
bool flag;
void dfs(int v,int rmaxi){
    maxi[v]=0;
    if(a[v]) maxi[v]=max(maxi[v],a[v]);
    if(a[v]>rmaxi) flag=false; 
    if(ls[v]) {dfs(ls[v],(a[v]?a[v]:rmaxi)); maxi[v]=max(maxi[v],maxi[ls[v]]);}
    if(rs[v]) {dfs(rs[v],(a[v]?a[v]:rmaxi)); maxi[v]=max(maxi[v],maxi[rs[v]]);}
    if(!a[v]) vec.push_back(P(maxi[v],rmaxi));
}
bool cmp(P p,P q){
    return p.S<q.S;
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) {ls[i]=rs[i]=fa[i]=0;}
        t=0;
        for(int i=1;i<=n;i++){
            while(t&&p[st[t-1]]<p[i]) ls[i]=st[--t];
            if(t) rs[st[t-1]]=i;
            st[t++]=i;
        }
        root=0;
        for(int i=1;i<=n;i++) fa[ls[i]]=fa[rs[i]]=i;
        for(int i=1;i<=n;i++) if(!fa[i]) root=i;
        int k=0;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); if(!a[i]) k++;}
        vec.clear();
        flag=true;
        dfs(root,INF-1);
        vector<int> has;
        for(int i=0;i<k-1;i++){
            int x;
            scanf("%d",&x);
            has.push_back(x);
        }
        sort(has.begin(),has.end());
        sort(vec.begin(),vec.end(),cmp);
        int now=0;
        int rb=INF,lb=-INF;
        set<int> s;
        for(int i=0;i<(int)vec.size();i++){
            while(now<(int)has.size()&&vec[i].S>=has[now]){
                s.insert(has[now]);
                now++;
            }
            auto it=s.lower_bound(vec[i].F);
            if(it==s.end()){
                if(rb==INF) rb=vec[i].S;
                else flag=false;
            }
            else{
                s.erase(it);
            }
        }
        s.clear(); now=(int)has.size()-1;
        sort(vec.begin(),vec.end(),greater<P>());
        for(int i=0;i<(int)vec.size();i++){
            while(now>=0&&vec[i].F<=has[now]){
                s.insert(has[now]);
                now--;
            }
            auto it=s.upper_bound(vec[i].S);
            if(it==s.begin()){
                if(lb==-INF) lb=vec[i].F;
                else flag=false;
            }
            else {
                s.erase(--it);
            }
        }
        for(int i=0;i<q;i++){
            int d; scanf("%d",&d);
            if(!flag) puts("NO");
            else if(d>=lb&&d<=rb) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}

