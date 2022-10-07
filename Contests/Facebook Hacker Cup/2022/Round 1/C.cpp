#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 7000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
int T,n,k,d;
struct P{
    ll x,y;
    P() {}
    P(ll x,ll y):x(x),y(y){}
    P operator+(P p){
        return P(x+p.x,y+p.y);
    }
    P operator-(P p){
        return P(x-p.x,y-p.y);
    }
    P operator *(ll d){
        return P(x*d,y*d);
    }
    ll dot(P p){
        return x*p.x+y*p.y;
    }
    ll det(P p){
        return x*p.y-y*p.x;
    }
};
bool cmp_x(const P& p,const P& q){
    if(p.x!=q.x) return p.x<q.x;
    return p.y<q.y;
}
vector<P> convex_hull(vector<P>& ps,int n){
    sort(ps.begin(),ps.end(),cmp_x);
    int k=0;
    vector<P> qs(n*2);
    for(int i=0;i<n;i++){
        while(k>1&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++]=ps[i];
    }
    for(int i=n-2,t=k;i>=0;i--){
        while(k>t&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
}
ll dp[MAXN];
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d%d",&n,&k,&d);
        vector<P> points;
        for(int i=0;i<n;i++)
        {
            ll x,y;
            scanf("%lld%lld",&x,&y);
            points.push_back(P(x,y));
        }
        vector<P> ch=convex_hull(points,n);
        sort(ch.begin(),ch.end(),cmp_x);
        int sz=(int)ch.size();
        for(int i=0;i<sz;i++) dp[i]=INF;
        dp[sz-1]=0;
        for(int i=sz-2;i>=0;i--)
            for(int j=i+1;j<sz;j++)
            {
                ll d2=(ch[j].x-ch[i].x)*(ch[j].x-ch[i].x)+(ch[j].y-ch[i].y)*(ch[j].y-ch[i].y);
                if(d2<=1LL*d*d) dp[i]=min(dp[i],dp[j]+max(1LL*k,d2));
            }
        printf("Case #%d: %lld\n",t,dp[0]==INF?-1:dp[0]);
    }
    return 0;
}

