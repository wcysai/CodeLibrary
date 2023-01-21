#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN],x;
bool dp[MAXN],ndp[MAXN];
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
    memset(dp,false,sizeof(dp)); dp[0]=true;
    for(int i=1;i<=n;i++){
        memset(ndp,false,sizeof(ndp));
        for(int j=0;j<=x;j++){
            if(!dp[j]) continue;
            for(int k=0;k<=b[i]&&j+k*a[i]<=x;k++){
                ndp[j+k*a[i]]=true;
            }
        }
        swap(dp,ndp);
    }
    if(dp[x]) puts("Yes"); else puts("No");
    return 0;
}

