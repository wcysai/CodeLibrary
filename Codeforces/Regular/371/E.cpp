#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
int dp[MAXN];
bool solve(int len,vector<int> &pos,int k){
    //printf("len=%d k=%d\n",len,k);
    //for(auto x:pos) printf("%d ",x);
    //printf("\n");
    //printf("dp0=%d\n",dp[0]);
    for(int i=1;i<=(int)pos.size();i++){
        int x=pos[i-1];
        dp[i]=dp[i-1];
        //go right
        if(dp[i-1]>=x-1) dp[i]=max(dp[i],x+k);
        //go left
        if(dp[i-1]>=x-k-1) dp[i]=max(dp[i],x);
        if(i>=2&&dp[i-2]>=x-k-1) dp[i]=max(dp[i],pos[i-2]+k);
        //printf("i=%d dp=%d\n",i,dp[i]);
    }
    return dp[pos.size()]>=len;
}
int b[MAXN];
bool check(int k){
    int pos=-1;
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]>k){
            pos=i;
        }
    }
    if(a[1]+m-a[n]>k) pos=1;
    //printf("k=%d pos=%d\n",k,pos);
    if(pos==-1) return true;
    int x=a[pos]-1;
    for(int i=1;i<=n;i++){
        b[i]=a[i]-x;
        while(b[i]<=0) b[i]+=m;
    }
    sort(b+1,b+n+1);
    vector<int> tmp;
    //no intersection
    dp[0]=0;
    for(int i=1;i<=n;i++) tmp.push_back(b[i]);
    if(solve(m,tmp,k)) return true;
    //first go left
    tmp.clear();
    for(int i=2;i<=n;i++) tmp.push_back(b[i]);
    dp[0]=1;
    if(solve(m-k,tmp,k)) return true;
    tmp.clear();
    //second go left, first go right
    if(n>=2&&b[2]<=k+1){
        int len=(k+1)-b[2];
        dp[0]=k+1;
        for(int i=3;i<=n;i++){
            tmp.push_back(b[i]);
        }
        if(solve(m-len,tmp,k)) return true;
    }

    return false;
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=-1,r=m;
    while(r-l>1){
        int mid=(l+r)/2;
        if(check(mid)) r=mid; else l=mid;
    }
    printf("%d\n",r);
    return 0;
}

