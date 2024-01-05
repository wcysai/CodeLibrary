#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,a[MAXN],b[MAXN];
vector<int> dis;
int dp[MAXN][MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    int ans=0,x=0,y=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(a[i]==b[j]){
                dp[i][j]=max(dp[i][j],1);
                for(int k=1;k<j;k++) if(b[k]<b[j]&&dp[i-1][k]!=-1) dp[i][j]=max(dp[i][j],dp[i-1][k]+1);
            }
            if(dp[i][j]>ans){
                ans=dp[i][j];
                x=i; y=j;
            }
        }
    printf("%d\n",ans);
    vector<int> res;
    while(ans){
        if(ans==1){
            res.push_back(b[y]);
            break;
        }
        if(x&&dp[x-1][y]==dp[x][y]) x--;
        else{
            res.push_back(b[y]);
            assert(a[x]==b[y]);
            x--; y--; ans--;
            while(dp[x][y]!=ans||b[y]>=res.back()) y--;
        }
    }
    reverse(res.begin(),res.end());
    for(auto x:res) printf("%d ",x);
    printf("\n");
    return 0;
}

