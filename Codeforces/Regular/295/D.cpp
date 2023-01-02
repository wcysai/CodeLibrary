#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,m,k,a[MAXN],t[MAXN];
bool cmp(pair<P,int> p,pair<P,int> q){
    return 1LL*p.F.F*q.F.S>1LL*q.F.F*p.F.S;
}
vector<P> v[MAXN][3];
vector<pair<P,int> > vv;
vector<int> ans;
int main()
{
    scanf("%d%d%d",&k,&n,&m);
    for(int i=1;i<=k;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        int y,z;
        scanf("%d%d%d",&t[i],&y,&z);
        t[i]--; v[y][t[i]].push_back(P(z,i));
    }
    for(int i=1;i<=k;i++){
        if(v[i][0].size()){
            sort(v[i][0].begin(),v[i][0].end(),greater<P>());
            if(v[i][0][0].F>a[i]) v[i][1].push_back(P(v[i][0][0].F-a[i],v[i][0][0].S));
        }
        sort(v[i][1].begin(),v[i][1].end(),greater<P>());
        ll s=a[i];
        for(int j=0;j<(int)v[i][1].size();j++){
            vv.push_back(make_pair(P(v[i][1][j].F,s),v[i][1][j].S));
            s+=v[i][1][j].F;
        }
        for(int j=0;j<(int)v[i][2].size();j++) vv.push_back(make_pair(P(v[i][2][j].F-1,1),v[i][2][j].S));
    }
    sort(vv.begin(),vv.end(),cmp);
    int sz=(int)vv.size();
    for(int i=0;i<min(m,sz);i++) if(t[vv[i].S]==0) ans.push_back(vv[i].S);
    for(int i=0;i<min(m,sz);i++) if(t[vv[i].S]==1) ans.push_back(vv[i].S);
    for(int i=0;i<min(m,sz);i++) if(t[vv[i].S]==2) ans.push_back(vv[i].S);
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);
    printf("\n");
    return 0;
}

