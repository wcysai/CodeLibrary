#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n,k;
P a[MAXN];
db dp[MAXN][MAXN];
db res[MAXN];
vector<P> v;
void upd(db &a,db b) {a=min(a,b);}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {scanf("%d%d",&a[i].S,&a[i].F); if(a[i].F==-1) a[i].F=INF;}
    sort(a+1,a+n+1);
    vector<int> v;
    for(int i=n;i>=1;i--){
        v.push_back(a[i].S);
        if(i-1<k){
            sort(v.begin(),v.end());
            for(int j=0;j<k-(i-1);j++) res[i]+=v[j];
        }
        //printf("i=%d res=%.10Lf\n",i,res[i]);
    }
    db ans=res[1];
    for(int goal=1;goal<=k;goal++){
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=INF;
        dp[0][0]=0;
        for(int i=0;i<k;i++){
            for(int j=0;j<=i;j++){
                upd(dp[i+1][j],dp[i][j]+(db)1.0*a[i+1].S/(goal+1));
                if(a[i+1].F<1e8) upd(dp[i+1][j+1],dp[i][j]+(db)1.0*a[i+1].F/(j+1));
            }
        }
        for(int i=goal;i<=k;i++) ans=min(ans,dp[i][goal]+res[i+1]/(goal+1));
    }
            //printf("i=%d j=%d ans=%.10Lf\n",i,j,ans);
    printf("%.10Lf\n",ans);
    return 0;
}

