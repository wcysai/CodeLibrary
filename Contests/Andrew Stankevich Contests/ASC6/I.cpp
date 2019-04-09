#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int r,n,m;
vector<int> v1,v2;
vector<int> G[MAXN];
void add(int &a,int b) {a+=b; if(a>=r) a-=r;}
void add_edge(int u,int v)
{
    G[u].push_back(v);
}
int find_val(vector<int> &v,int x)
{
    int ans=0,base=1;
    for(int i=0;i<(int)v.size();i++)
    {
        add(ans,1LL*base*v[i]%r);
        base=1LL*base*x%r;
    }
    return ans;
}
int go1[MAXN],go2[MAXN],res;
bool vis[MAXN];
int fa[MAXN],mg;
bool valid1[MAXN],valid2[MAXN];
bool good[MAXN];
int find(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void unite(int x,int y)
{
    x=find(x); y=find(y);
    if(x==y) return;
    res--;
    fa[x]=y;
}
void nogood(int x)
{
    good[find(x)]=false;
}
vector<int> ans;
void mult2()
{
    int carry=0;
    for(int i=0;i<(int)ans.size();i++) 
    {
        int res=ans[i]*2+carry;
        ans[i]=res%10;
        carry=res/10;
    }
    if(carry) ans.push_back(1);
}
void print()
{
    for(int i=(int)ans.size()-1;i>=0;i--) printf("%d",ans[i]);
}
mat A;
int main()
{
    freopen("stable.in","r",stdin);
    freopen("stable.out","w",stdout);
    scanf("%d",&r);
    scanf("%d",&n); v1.resize(n+1); for(int i=0;i<=n;i++) scanf("%d",&v1[i]);
    reverse(v1.begin(),v1.end());
    scanf("%d",&m); v2.resize(m+1); for(int i=0;i<=m;i++) scanf("%d",&v2[i]);
    reverse(v2.begin(),v2.end());
    for(int i=0;i<=r-1;i++)
    {
        int x=find_val(v1,i); add_edge(i,x); go1[i]=x;
        x=find_val(v2,i); add_edge(i,x); go2[i]=x;
    }
    memset(valid1,false,sizeof(false));
    memset(valid2,false,sizeof(false));
    memset(vis,false,sizeof(vis));
    for(int i=0;i<r;i++) fa[i]=i;
    for(int i=0;i<=r-1;i++)
    {
        if(!vis[i])
        {
            int now=i;
            vector<int> ve;ve.clear();
            do
            {
                ve.push_back(now);
                if(vis[now]) break;
                vis[now]=true;
                now=go1[now];
            }while(true);
            reverse(ve.begin(),ve.end());
            while(ve.front()!=ve.back())
            {
                ve.pop_back();
            }
            ve.pop_back();
            for(int j=0;j<(int)ve.size();j++) valid1[ve[j]]=true;
            if(ve.size()) A.push_back(ve);
        }
    }
    memset(vis,false,sizeof(vis));
    for(int i=0;i<=r-1;i++)
    {
        if(!vis[i])
        {
            int now=i;
            vector<int> ve;ve.clear();
            do
            {
                ve.push_back(now);
                if(vis[now]) break;
                vis[now]=true;
                now=go2[now];
            }while(true);
            reverse(ve.begin(),ve.end());
            while(ve.front()!=ve.back())
            {
                ve.pop_back();
            }
            ve.pop_back();
            for(int j=0;j<(int)ve.size();j++) valid2[ve[j]]=true;
            if(ve.size()) A.push_back(ve);
        }
    }
    for(auto xx:A)
    {
        for(int i=1;i<(int)xx.size();i++) unite(xx[i],xx[i-1]);
    }
    memset(good,true,sizeof(good));
    memset(vis,false,sizeof(vis));
    for(int i=0;i<r;i++) if(!valid1[i]||!valid2[i]) nogood(i);
    res=0;
    for(int i=0;i<r;i++) if(!vis[find(i)]&&good[find(i)]) {vis[find(i)]=true; res++;}
    ans.push_back(1);
    for(int i=0;i<res;i++) mult2();
    print();
    return 0;
}
