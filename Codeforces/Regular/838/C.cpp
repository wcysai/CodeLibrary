#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
char str[MAXN];
int dp[MAXN];
const int shift=200000;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",str+1);
        int x=(str[1]=='1'?1:-1);
        int ans=1;
        int sum=1,last=x;
        for(int i=2;i<=n;i++)
        {
            x=(str[i]=='1'?1:-1);
            if(last==x) 
            {
                sum=2LL*sum%MOD;
            }
            else 
            {
                sum=1;
            }
            add(ans,sum);
            last=x;
        }
        printf("%d\n",ans);
    }
    return 0;
}

