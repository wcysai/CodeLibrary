#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,p[MAXN],dp[MAXN],a[MAXN];
int st[MAXN][20];
int pre[MAXN],last[MAXN],dir[MAXN];
void prepare(int n){
    pre[1]=0;
    for(int i=2;i<=n;i++){
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
}
void init(int n,int *arr){
    for(int i=n;i>=1;--i){
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r){
    if(l>r) return 0;
    int len=r-l+1,k=pre[len];
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int ans[MAXN];
int main(){
    prepare(300000);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {scanf("%d",&p[i]); a[i]=i+p[i];}
        init(n,a);
        int now=-1;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]; last[i]=i-1; dir[i]=1;
            //turn to right
            if(dp[i-1]>=i) dp[i]=max(dp[i],i+p[i]);
            //turn to left
            //find first position to "connect with" i-p[i] (dp[j]>=i-p[i]-1)
            int l=-1,r=i;
            while(r-l>1){
                int mid=(l+r)/2;
                if(dp[mid]>=i-p[i]-1) r=mid; else l=mid;
            }
            //turn all of [j,i-1] to right
            if(r<i){
                int rb=max(max(i-1,dp[r]),query(r+1,i-1));
                if(rb>dp[i]){
                    dp[i]=rb;
                    last[i]=r;
                    dir[i]=0;
                }
            }
            if(dp[i]>=n) now=i; 
        }
        if(now==-1) {puts("NO"); continue;}
        puts("YES");
        for(int i=now+1;i<=n;i++) ans[i]=1;
        while(now){
            if(dir[now]==1){
                ans[now]=1; now--;
            }
            else{
                ans[now]=0;
                for(int j=last[now]+1;j<now;j++) ans[j]=1;
                now=last[now];
            }
        }
        for(int i=1;i<=n;i++) if(ans[i]) printf("R"); else printf("L");
        printf("\n");
    }
    return 0;
}

