#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN];
int l[MAXN],r[MAXN],dp[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d",&a[i],&b[i]);
        l[a[i]]=i; r[b[i]]=i;
    }
    for(int i=1;i<=2*n;i++) if(!l[i]) l[i]=l[i-1];
    dp[2*n+1]=1;
    for(int i=2*n;i>=1;i--){
        if(r[i]) dp[i]=2LL*dp[i+1]%MOD;
        else{
            int id=l[i],x=a[id],y=b[id];
            dp[i]=dp[i+1];
            int nxt=l[y];
            dec(dp[i],dp[b[nxt]+1]);
        }
    }
    printf("%d\n",dp[1]);
    return 0;
}

