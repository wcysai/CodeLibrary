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
void solve(vector<Point> v)
{
    while(v.size())
    {
        int sz=(int)v.size();
        //sort(v.begin(),v.end(),cmp);
        Point p=v[0];
        resp=p; v.erase(v.begin());
        sort(v.begin(),v.end(),gcmp);
        int st=0,ed=0,cnt=0,need=sz/2;
        while(st<sz-1)
        {
            while(cnt<sz-1&&xmult(p,v[st],v[ed])>=0) {cnt++; ed=(ed+1)%(sz-1);}
            if(cnt==need)
            {
                int tmp=0;
                for(int j=0;j<sz-1;j++) if(xmult(p,v[st],v[j])>=0) tmp++;
                assert(tmp==need);
                ans.push_back(make_pair(p.id,v[st].id));
                v.erase(v.begin()+st);
                break;
            }
            cnt--;
            st++;
        }
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
        printf("Case #%d:",_);
        solve(v);
        for(auto p:ans) match[p.F]=p.S,match[p.S]=p.F;
        for(int i=1;i<=2*N;i++) printf(" %d",match[i]);
        puts("");
    }
    return 0;
}
