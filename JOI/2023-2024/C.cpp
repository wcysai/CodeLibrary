#include<bits/stdc++.h>
#define MAXN 500005
#define MAXM 1005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,l,q,x[MAXN];
vector<P> v;
vector<int> sum;
int s[MAXN],t[MAXN],val[MAXN];
ll dp[2][MAXM][MAXM][2];
void upd(ll &x,ll y) {x=min(x,y);}
int main(){
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    sort(x+1,x+n+1);
    for(int i=1;i<=n;i++){
        if(v.size()>0&&v.back().F==x[i]) v.back().S++;
        else v.push_back(P(x[i],1));
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++) scanf("%d%d%d",&s[i],&t[i],&val[i]);
    int m=(int)v.size();
    //printf("m=%d\n",m);
    if(m>=1000){
        for(int i=0;i<q;i++) puts("No");
        return 0;
    }
    sum.resize(m+1);
    for(int i=1;i<=m;i++) sum[i]=sum[i-1]+v[i-1].S;
    for(int i=1;i<=m;i++)
        for(int j=i;j<=m;j++)
            dp[0][i][j][0]=dp[0][i][j][1]=dp[1][i][j][0]=dp[1][i][j][1]=INF;
    dp[0][1][m][0]=dp[1][1][m][1]=0;
    for(int id=0;id<2;id++){
        for(int len=m;len>=2;len--){
            for(int i=1;i+len-1<=m;i++){
                int j=i+len-1;
                int num=sum[m]-(sum[j]-sum[i-1]);
                upd(dp[id][i+1][j][0],dp[id][i][j][0]+1LL*(num+v[i-1].S+1)*(v[i].F-v[i-1].F));
                upd(dp[id][i+1][j][1],dp[id][i][j][0]+1LL*(num+v[i-1].S+1)*(v[j-1].F-v[i-1].F));
                upd(dp[id][i][j-1][0],dp[id][i][j][1]+1LL*(num+v[j-1].S+1)*(v[j-1].F-v[i-1].F));
                upd(dp[id][i][j-1][1],dp[id][i][j][1]+1LL*(num+v[j-1].S+1)*(v[j-1].F-v[j-2].F));
            }
        }
    }
    for(int i=0;i<q;i++){
        ll ans=INF;
        int id=lower_bound(v.begin(),v.end(),P(t[i],0))-v.begin();
        if(id!=m){
            upd(ans,1LL*(n+1)*max(t[i]-v[id].F,v[id].F-t[i])+n+max(s[i]-v[0].F,v[0].F-s[i])+min(dp[0][id+1][id+1][0],dp[0][id+1][id+1][1]));
            upd(ans,1LL*(n+1)*max(t[i]-v[id].F,v[id].F-t[i])+n+max(s[i]-v[m-1].F,v[m-1].F-s[i])+min(dp[1][id+1][id+1][0],dp[1][id+1][id+1][1]));
        }
        if(id!=0){
            upd(ans,1LL*(n+1)*max(t[i]-v[id-1].F,v[id-1].F-t[i])+n+max(s[i]-v[0].F,v[0].F-s[i])+min(dp[0][id][id][0],dp[0][id][id][1]));
            upd(ans,1LL*(n+1)*max(t[i]-v[id-1].F,v[id-1].F-t[i])+n+max(s[i]-v[m-1].F,v[m-1].F-s[i])+min(dp[1][id][id][0],dp[1][id][id][1]));
        }
        //printf("ans=%lld\n",ans);
        if(ans<=val[i]) puts("Yes"); else puts("No");
    }
    return 0;
}

