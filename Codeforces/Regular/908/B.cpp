#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN],b[MAXN];
int dp[MAXN];
vector<int> save[MAXN];
vector<int> ans;
bool mark[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        sort(b+1,b+m+1,greater<int>());
       /* fill(dp+1,dp+n+1,INF);
        int maxi=0;
        for(int i=1;i<=n;i++) save[i].clear();
        for(int i=1;i<=n;i++){
            int pos=lower_bound(dp+1,dp+n+1,a[i])-dp;
            save[pos].push_back(i);
            maxi=max(maxi,pos);
            dp[pos]=a[i];
        }
        for(int i=1;i<=n;i++) mark[i]=false;
        for(int i=1;i<=maxi;i++) mark[save[i].back()]=true;
        int now=1;*/
        ans.clear();
        int now=1;
        for(int i=1;i<=n;i++){
            while(now<=m&&b[now]>=a[i]) {ans.push_back(b[now]); now++;}
            ans.push_back(a[i]);
        }
        while(now<=m) {ans.push_back(b[now]); now++;}
        for(auto x:ans) printf("%d ",x);
        printf("\n");
    }
    return 0;
}

