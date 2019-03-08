#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 fkaod
#define y1 dajosk
#define x2 fdsojfs
#define y2 vdijsfjs
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
P a[MAXN];
int x1,y1,x2,y2;
vector<int> x,y;
vector<P> v;
int dp[MAXN];
void find(int &k,vector<int> &a)
{
    k=lower_bound(a.begin(),a.end(),k)-a.begin()+1;
}
bool cmp(P p,P q)
{
    return abs(p.S-y1)<abs(q.S-y1);
}
const double PI=acos(-1.0);
int main()
{
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    int s=abs(x1-x2)+abs(y1-y2);
    int rg=min(abs(x1-x2),abs(y1-y2));
    x.push_back(x1);x.push_back(x2);y.push_back(y1);y.push_back(y2);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S);
        x.push_back(a[i].F);y.push_back(a[i].S);
    }
    sort(x.begin(),x.end());sort(y.begin(),y.end());
    x.erase(unique(x.begin(),x.end()),x.end());y.erase(unique(y.begin(),y.end()),y.end());
    find(x1,x);find(x2,x);find(y1,y);find(y2,y);
    for(int i=0;i<n;i++) {find(a[i].F,x);find(a[i].S,y);}
    if(x1>x2) {swap(x1,x2); swap(y1,y2);}
    for(int i=0;i<n;i++) if(a[i].F>=min(x1,x2)&&a[i].F<=max(x1,x2)&&a[i].S>=min(y1,y2)&&a[i].S<=max(y1,y2)) v.push_back(a[i]);
    sort(v.begin(),v.end(),cmp);
    //printf("%d\n",(int)v.size());
    //printf("%d %d %d %d\n",x1,y1,x2,y2);
    //for(int i=0;i<(int)v.size();i++) printf("%d %d\n",v[i].F,v[i].S);
    fill(dp,dp+(int)v.size(),INF);
    for(int i=0;i<(int)v.size();i++) *lower_bound(dp,dp+(int)v.size(),v[i].F)=v[i].F;
    int k=lower_bound(dp,dp+(int)v.size(),INF)-dp;
    //printf("%d\n",k);
    if(k==rg+1) printf("%.15f\n",100.0*s-20.0*k+5*PI*(k-1)+10*PI);
    else printf("%.15f\n",100.0*s-20.0*k+5*PI*k);
    return 0;
}

