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
int n,k,a[MAXN];
vector<int> divi[MAXN];
int dp[MAXN];
int cnt[MAXN];
int inv[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    inv[1]=1;
    for(int i=2;i<=500000;i++)
        inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    for(int i=1;i<=500000;i++)
        for(int j=i;j<=500000;j+=i)
            divi[j].push_back(i);
    scanf("%d",&n);
    dp[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=(int)divi[i].size()-1;j>=0;j--){
            int x=divi[i][j];
            cnt[x]=n/x;
            for(int k=1;k<(int)divi[i/x].size();k++) cnt[x]-=cnt[x*divi[i/x][k]];
        }
        int res=0;
        for(int j=(int)divi[i].size()-2;j>=0;j--) {
            int x=divi[i][j];
            add(res,1LL*cnt[x]*dp[x]%MOD);
        }
        add(res,n);
        dp[i]=1LL*res*inv[n-cnt[i]]%MOD;
    }
    for(int i=1;i<=n;i++) printf("%d%c",dp[i],i==n?'\n':' ');
    return 0;
}

