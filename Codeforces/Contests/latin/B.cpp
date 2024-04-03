#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n,t,s;
db p1[6],p2[6];
int g1[6],g2[6],b1[6],b2[6];
db dp[6][5005];
vector<int> timing[6];
int mini[6];
int main(){
    scanf("%d%d%d",&n,&t,&s);
    for(int i=1;i<=n;i++) {
        scanf("%Lf%d%d%Lf%d%d",&p1[i],&g1[i],&b1[i],&p2[i],&g2[i],&b2[i]);
        p1[i]/=100; p2[i]/=100;
    }
    mini[n]=min(g1[n],g2[n]);
    for(int i=n-1;i>=1;i--){
        mini[i]=mini[i+1]+min(g1[i],g2[i]);
    }
    for(int i=1;i<=4;i++)
        for(int j=0;j<=5000;j++)
            dp[i][j]=0;
    mini[1]+=s;
    assert(mini[1]<t);
    timing[1].push_back(t);
    for(int i=1;i<=n;i++){
        sort(timing[i].begin(),timing[i].end());
        timing[i].erase(unique(timing[i].begin(),timing[i].end()),timing[i].end());
        if(i==n) break;
        for(auto x:timing[i]){
            int rem=(i==1?x-s:x);
            if(rem-g1[i]>mini[i+1]) timing[i+1].push_back(rem-g1[i]);
            if(rem-b1[i]>mini[i+1]) timing[i+1].push_back(rem-b1[i]);
            if(rem-g2[i]>mini[i+1]) timing[i+1].push_back(rem-g2[i]);
            if(rem-b2[i]>mini[i+1]) timing[i+1].push_back(rem-b2[i]);
        }
    }
    for(int i=1;i<=n;i++)
        for(auto x:timing[i])
            dp[i][x]=1e14;
    for(int iter=0;iter<100;iter++){
        for(int i=4;i>=2;i--){
            for(auto x:timing[i]){
                //strat1, go if good, restart if bad
                if(x-g1[i]>mini[i+1]) dp[i][x]=min(dp[i][x],p1[i]*(g1[i]+dp[i+1][x-g1[i]])+(1-p1[i])*dp[1][t]);
                //strat1, go if good or bad
                if(x-b1[i]>mini[i+1]) dp[i][x]=min(dp[i][x],p1[i]*(g1[i]+dp[i+1][x-g1[i]])+(1-p1[i])*(b1[i]+dp[i+1][x-b1[i]]));
                //strat2, go if good, restart if bad
                if(x-g2[i]>mini[i+1]) dp[i][x]=min(dp[i][x],p2[i]*(g2[i]+dp[i+1][x-g2[i]])+(1-p2[i])*dp[1][t]);
                //strat2, go if good or bad
                if(x-b2[i]>mini[i+1]) dp[i][x]=min(dp[i][x],p2[i]*(g2[i]+dp[i+1][x-g2[i]])+(1-p2[i])*(b2[i]+dp[i+1][x-b2[i]]));
            }
        }        
        //strat1, go if good, restart if bad
        if(t-s-g1[1]>mini[2]) dp[1][t]=min(dp[1][t],s/p1[1]+g1[1]+dp[2][t-s-g1[1]]);
        //strat1, go if good or bad
        if(t-s-b1[1]>mini[2]) dp[1][t]=min(dp[1][t],s+p1[1]*(g1[1]+dp[2][t-s-g1[1]])+(1-p1[1])*(b1[1]+dp[2][t-s-b1[1]]));
        //strat2, go if good, restart if bad
        if(t-s-g2[1]>mini[2]) dp[1][t]=min(dp[1][t],s/p2[1]+g2[1]+dp[2][t-s-g2[1]]);
        //strat2, go if good or bad
        if(t-s-b2[1]>mini[2]) dp[1][t]=min(dp[1][t],s+p2[1]*(g2[1]+dp[2][t-s-g2[1]])+(1-p2[1])*(b2[1]+dp[2][t-s-b2[1]]));
    }
    printf("%.15Lf\n",dp[1][t]);
    return 0;
}

