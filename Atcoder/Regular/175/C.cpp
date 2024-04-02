#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,l[MAXN],r[MAXN],f[MAXN],g[MAXN];
ll dp[MAXN];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
    f[n]=l[n]; g[n]=r[n]; dp[n]=0;
    for(int i=n-1;i>=1;i--){
        if(r[i]<=f[i+1]) f[i]=g[i]=r[i];
        else if(l[i]>=g[i+1]) f[i]=g[i]=l[i];
        else{
            f[i]=max(l[i],f[i+1]); g[i]=min(r[i],g[i+1]); 
        }
        dp[i]=dp[i+1]+max(f[i]-f[i+1],f[i+1]-f[i]);
    }
    int last;
    for(int i=1;i<=n;i++){
        if(i==1) last=f[i];
        else{
            if(last<f[i]) last=max(l[i],last);
            else if(last>g[i]) last=g[i];
        }
        printf("%d%c",last,i==n?'\n':' ');
    }
    printf("\n");
    return 0;
}

