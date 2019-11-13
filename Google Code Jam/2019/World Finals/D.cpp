#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
int T,N;
int match[MAXN];
struct Point
{
    int x,y,id;
};
vector<Point> v;
Point resp;
vector<pair<int,int> > ans;
ll xmult(const Point &po,const Point &ps,const Point &pe)
{
    return 1LL*(ps.x-po.x)*(pe.y-po.y)-1LL*(pe.x-po.x)*(ps.y-po.y);
}
bool gcmp(const Point &ta, const Point &tb)
{
    ll tmp=xmult(resp,ta,tb);
    return tmp>0;
}
void solve(vector<Point> lhs,vector<Point> rhs)
{
    if(lhs.size()==0&&rhs.size()==0) return;
    vector<Point> all; all.clear();
    all.insert(all.begin(),lhs.begin(),lhs.end()); all.insert(all.begin(),rhs.begin(),rhs.end());
    int sz=(int)all.size();
    int pos=wcy()%sz,ppos;
    Point p=all[pos],q;
    all.erase(all.begin()+pos);
    resp=p;
    sort(all.begin(),all.end(),gcmp);
    int st=0,ed=0,cnt=0,need=sz/2;
    while(st<sz-1)
    {
        while(cnt<sz-1&&xmult(p,all[st],all[ed])>=0) {cnt++; ed=(ed+1)%(sz-1);}
        if(cnt==need)
        {
            q=all[st];
            break;
        }
        cnt--;
        st++;
    }
    vector<Point> nlhs1,nrhs1,nlhs2,nrhs2;
    nlhs1.clear(); nrhs1.clear(); nlhs2.clear(); nrhs2.clear();
    ans.push_back(make_pair(p.id,q.id));
    for(auto r:lhs)
    {
        if(r.id==p.id||r.id==q.id) continue;
        if(xmult(p,q,r)>0) nlhs1.push_back(r); else nlhs2.push_back(r);
    }
    for(auto r:rhs)
    {
        if(r.id==p.id||r.id==q.id) continue;
        if(xmult(p,q,r)>0) nrhs2.push_back(r); else nrhs1.push_back(r);
    }
    if(!rhs.size()) solve(nlhs1,nlhs2);
    else
    {
        solve(nlhs1,nrhs1);
        solve(nlhs2,nrhs2);
    }
}
int main()
{
    scanf("%d",&T);
    for(int _=1;_<=T;_++)
    {
        v.clear(); ans.clear();
        scanf("%d",&N);
        for(int i=1;i<=2*N;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v.push_back((Point){x,y,i});
        }
        solve(v,vector<Point>());
        printf("Case #%d:",_);
        for(auto p:ans) match[p.F]=p.S,match[p.S]=p.F;
        for(int i=1;i<=2*N;i++) printf(" %d",match[i]);
        puts("");
    }
    return 0;
}
