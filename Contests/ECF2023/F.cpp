#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,k,a[MAXN];
int dp[MAXN],pos[MAXN];
int bit[MAXN];
int sum(int i){
    int s=0;
    while(i>0){
        s+=bit[i]; 
        i-=i&-i;
    }
    return s;
}
void add(int i,int x){
    while(i<=n){
        bit[i]+=x;
        i+=i&-i;
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); pos[a[i]]=i;} 
        for(int i=1;i<=n;i++) bit[i]=0;
        ll inv=0;
        for(int i=1;i<=n;i++){
            inv+=(i-1-sum(a[i]));
            add(a[i],1);
        }
        dp[0]=0;
        for(int i=1;i<=n;i++) dp[i]=INF;
        for(int i=0;i<n;i++){
            dp[i+1]=min(dp[i+1],dp[i]);
            if(pos[i+2]<pos[i+1]) dp[i+2]=min(dp[i+2],dp[i]-1);
        }
        inv+=dp[n];
        printf("%lld\n",inv);
    }
    return 0;
}

