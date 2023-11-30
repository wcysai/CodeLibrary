#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
vector<int> G[MAXN]; 
int odeg[MAXN];
double ans[MAXN];
double dp[5005][5005];
int main()
{
    dp[2][1]=0.5; dp[2][2]=0.0;
    for(int i=4;i<=5000;i+=2){
        dp[i][1]=1.0/i;
        for(int j=2;j<=i;j++){
            dp[i][j]=1.0*(j-2)*dp[i-2][j-2]+1.0*(i-j)*dp[i-2][j-1];
            dp[i][j]/=i;
        }
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) {G[i].clear(); odeg[i]=0;}
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            odeg[u]++; G[u].push_back(v);
        }
        for(int i=1;i<n;i++) ans[i]=0.0;
        ans[n]=1.0;
        for(int i=n-1;i>=1;i--){
            if(!odeg[i]){
                ans[i]=0.0;
                continue;
            }
            vector<double> v;
            for(auto to:G[i]) v.push_back(ans[to]);
            if(odeg[i]&1){
                for(int j=0;j<(int)v.size();j++) ans[i]+=v[j];
                ans[i]=ans[i]*1.0/odeg[i];
            }
            else{
                sort(v.begin(),v.end(),greater<double>());
                int d=odeg[i];
                for(int j=0;j<(int)v.size();j++) ans[i]+=v[j]*dp[d][j+1];
            }
        }
        printf("%.10f\n",ans[1]);
    }
    return 0;
}

