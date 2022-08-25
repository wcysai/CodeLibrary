#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,q,a[MAXN],p[MAXN];
int fa[MAXN],st[MAXN],t,ls[MAXN],rs[MAXN],mini[MAXN],maxi[MAXN],root;
vector<int> vec;
void dfs(int v)
{
    mini[v]=min(mini[v],a[v]); maxi[v]=max(maxi[v],a[v]);
    if(ls[v]) {maxi[ls[v]]=maxi[v]; dfs(ls[v]); mini[v]=max(mini[v],mini[ls[v]]);}
    if(rs[v]) {maxi[rs[v]]=maxi[v]; dfs(rs[v]); mini[v]=max(mini[v],mini[rs[v]]);}
    if(!a[v]) vec.push_back(P(mini[v],maxi[v]));
}
bool cmp(P p,P q)
{
    return p.S<q.S;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) {ls[i]=rs[i]=fa[i]=0;maxi[i]=INF;mini[i]=0;}
        t=0;
        for(int i=1;i<=n;i++)
        {
            while(t&&p[st[t-1]]<p[i]) ls[i]=st[--t];
            if(t) rs[st[t-1]]=i;
            st[t++]=i;
        }
        for(int i=1;i<=n;i++) fa[ls[i]]=fa[rs[i]]=i;
        for(int i=1;i<=n;i++) if(!fa[i]) root=i;
        int k=0;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); if(!a[i]) k++;}
        vec.clear();
        dfs(root);
        sort(vec.begin(),vec.end());
        assert(vec.size()==k);
        vector<int> has;
        for(int i=0;i<k-1;i++)
        {
            int x;
            scanf("%d",&x);
            has.push_back(x);
        }
        sort(has.begin(),has.end());
        for(auto x:vec) printf("%d ",x);
        puts("");
        for(auto x:has) printf("%d ",x);
        puts("");
        vector<bool> pre(k+1),suf(k+1);
        pre[0]=true;
        //pre/suf: 0 to k-1
        for(int i=0;i<k-1;i++) if((has[i]>=vec[i])&&(pre[i])) pre[i+1]=true; else pre[i+1]=false;
        suf[k-1]=true;
        for(int i=k-2;i>=0;i--) if((has[i]>=vec[i+1])&&(suf[i+1])) suf[i]=true; else suf[i]=false;
        for(int i=0;i<q;i++)
        {
            int x;
            scanf("%d",&x);
            int pos=lower_bound(has.begin(),has.end(),x)-has.begin();
            if(x>=vec[pos]&&pre[pos]&&suf[pos]) puts("YES"); else puts("NO");
        }
    }
    return 0;
}

