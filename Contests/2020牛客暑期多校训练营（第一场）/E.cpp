#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],dp[MAXN],mod;
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
int main()
{
    while(scanf("%d%d%d",&n,&m,&mod)==3)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        if(n-m>1||m-n>1) {puts("0"); continue;}
        int cur=0;
        for(int i=0;i<=n;i++) dp[i]=0;
        dp[0]=1;
    }
    return 0;
}