#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,cnt;
ll m;
int p[MAXN],r[MAXN];
void init(int n)
{
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
    cnt=n;
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    cnt--;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
vector<P> con;
vector<P> ncon;
int main()
{
    scanf("%d%lld%d",&n,&m,&q);
    init(n);
    for(int i=0;i<q;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(!z) con.push_back(P(x,y));
        else ncon.push_back(P(x,y));
    }
    for(auto p:con) unite(p.F,p.S);
    bool f=true;
    for(auto p:ncon)
    {
        if(same(p.F,p.S)) f=false;
    }
    if(!f) {puts("No"); return 0;}
    if(cnt==1)
    {
        if(m==n-1) puts("Yes"); else puts("No");
    }
    else
    {
        if(m>=n&&m<=n+1LL*cnt*(cnt-3)/2) puts("Yes"); else puts("No");
    }
    return 0;
}
