#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
P operator-(const P& lhs, const P& rhs) { return P(lhs.F-rhs.F,lhs.S-rhs.S); }
int n,m;
vector<P> row,col;
ll xmult(P a,P b)
{
    return 1LL*a.F*b.S-1LL*a.S*b.F;
}
ll xmult(P x,P y,P z)
{
    return xmult(y-x,z-x);
}
void convex(vector<P> &v)
{
    vector<P> tmp;
    for(auto p:v)
    {
        while(tmp.size()>1&&xmult(tmp[tmp.size()-2],tmp[tmp.size()-1],p)<=0) tmp.pop_back();
        tmp.push_back(p);
    }
    swap(tmp,v);
}
int main()
{
    freopen("iron.in","r",stdin);
    freopen("iron.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++)
    {
        int x;
        scanf("%d",&x); row.push_back(P(i,x));
    }
    for(int i=0;i<=m;i++)
    {
        int x;
        scanf("%d",&x); col.push_back(P(i,x));
    }
    convex(row); convex(col);
    int pos1=0,pos2=0;
    ll ans=0;
    while(pos1<(int)row.size()-1&&pos2<(int)col.size()-1)
    {
        if(xmult(row[pos1+1]-row[pos1],col[pos2+1]-col[pos2])<0)
        {
            ans+=1LL*(col[pos2+1].F-col[pos2].F)*row[pos1].S;
            pos2++;
        }
        else
        {
            ans+=1LL*(row[pos1+1].F-row[pos1].F)*col[pos2].S;
            pos1++;
        }
    }
    while(pos1<(int)row.size()-1)
    {
        ans+=1LL*(row[pos1+1].F-row[pos1].F)*col[pos2].S;
        pos1++;
    }
    while(pos2<(int)col.size()-1)
    {
        ans+=1LL*(col[pos2+1].F-col[pos2].F)*row[pos1].S;
        pos2++;
    }
    printf("%lld\n",ans);
}
