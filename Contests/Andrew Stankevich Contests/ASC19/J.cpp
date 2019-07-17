#include<bits/stdc++.h>
#define MAXN 100005
#define INF 100000000
#define MOD 100000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,ans,st;
vector<P> seg[2];
bool inter(P p,P q)
{
    if(p.S<q.F||q.S<p.F) return false;
    if(p.F<q.F&&p.S>q.S) return false;
    if(q.F<p.F&&q.S>p.S) return false;
    return true;
}
bool check(int l,int r,int dir)
{
    for(auto p:seg[dir]) if(inter(p,P(l,r))) return false;
    if(dir&&st>l&&st<r) return false;
    return true;
}
void solve(int pos,int mask,int dir)
{
    if(mask==(1<<n)-1)
    {
        for(auto p:seg[dir]) if(p.F<pos&&p.S>pos) return;
        ans++;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i)) continue;
        if(abs(pos-i)%2==0) continue;
        if(!check(min(pos,i),max(pos,i),dir)) continue;
        seg[dir].push_back(P(min(pos,i),max(pos,i)));
        solve(i,mask^(1<<i),dir^1);
        seg[dir].pop_back();
    }
}
int main()
{
    freopen("river.in","r",stdin);
    freopen("river.out","w",stdout);
    scanf("%d",&n);
    ans=0;
    for(int i=0;i<n;i++)
    {
        st=i;
        solve(i,(1<<i),0);
    }
    printf("%d\n",ans*2);
    return 0;
}
