#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,h[MAXN];
int st[MAXN],t;
int fa[MAXN],ls[MAXN],rs[MAXN],root;
vector<int> ans;
void solve2_left(int x,int val){
    if(!x) return;
    ans.push_back(val-h[x]);
    solve2_left(rs[x],val);
}
void solve2_right(int x,int val){
    if(!x) return;
    ans.push_back(val-h[x]);
    solve2_right(ls[x],val);
}
void solve1(int x){
    if(!x) return;
    solve1(ls[x]); solve1(rs[x]);
    solve2_left(ls[x],h[x]); solve2_right(rs[x],h[x]);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
        for(int i=1;i<=n;i++) ls[i]=rs[i]=fa[i]=0;
        t=0;
        ans.clear();
        for(int i=1;i<=n;i++)
        {
            while(t&&h[st[t-1]]<h[i]) ls[i]=st[--t];
            if(t) rs[st[t-1]]=i;
            st[t++]=i;
        }
        for(int i=1;i<=n;i++) fa[ls[i]]=fa[rs[i]]=i;
        for(int i=1;i<=n;i++) if(!fa[i]) root=i;
        solve1(root);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        printf("%d\n",(int)ans.size());
    }
    return 0;
}

