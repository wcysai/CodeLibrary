#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dp[MAXN],ndp[MAXN];
char s[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%s",s+1);
    n=strlen(s+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        memset(ndp,0,sizeof(ndp));
        for(int j=0;j<i;j++){
            if(!dp[j]) continue;
            if(s[i]!=')') add(ndp[j+1],dp[j]);
            if(s[i]!='('&&j) add(ndp[j-1],dp[j]);
        }
        swap(dp,ndp);
    }
    printf("%d\n",dp[0]);
    return 0;
}

