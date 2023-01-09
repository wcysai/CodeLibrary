#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define MAXM 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dp[MAXM],ndp[MAXM];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
const int shift=90000;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=-90000;i<=90000;i++) dp[i+shift]=(i==0?1:2);
    for(int i=n-2;i>=2;i--){
        memset(ndp,0,sizeof(ndp));
        for(int j=-90000;j<=90000;j++){
            if(j==0) add(ndp[j+shift],dp[a[i+1]+shift]);
            else{
                add(ndp[j+shift],dp[a[i+1]+j+shift]);
                add(ndp[j+shift],dp[a[i+1]-j+shift]);
            }
        }
        swap(dp,ndp);
    }
    printf("%d\n",dp[a[2]+shift]);
    return 0;
}

