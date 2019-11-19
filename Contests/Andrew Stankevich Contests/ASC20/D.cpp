#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int prime[MAXN];
bool is_prime[MAXN];
ll n;
int sieve(int n)
{
    int p=0;
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(i*prime[j]>n) break;
            is_prime[i*prime[j]]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
vector<int> fact;
bool check_sqr(ll x)
{
    int d=(int)sqrt(x);
    for(int i=max(0,d-10);i<=d+10;i++) if(1LL*i*i==x) return true;
    return false;
}
int part[40][40],p[40];
int dp[40][40];
int main()
{
    freopen("false.in","r",stdin);
    freopen("false.out","w",stdout);
    int p=sieve(1000000);
    scanf("%lld",&n);
    for(int i=0;i<p;i++)
    {
        if(n%prime[i]==0)
        {
            int cnt=0;
            while(n%prime[i]==0) n/=prime[i],cnt++;
            fact.push_back(cnt);
        }
    }
    if(fact.size()==0) {puts("1"); return 0;}
    else if(fact.size()==1)
    {
        assert(n!=1);
        if(check_sqr(n)) fact.push_back(2);  else fact.push_back(1);
    }
    assert(fact.size()==2);
    part[0][0]=1;
    for(int i=1;i<=30;i++)
        for(int j=1;j<=i;j++)
            part[i][j]=part[i-1][j-1]+part[i-j][j];
    int x=fact[0],y=fact[1];
    dp[0][0]=1;
    for(int di=0;di<=30;di++)
        for(int dj=0;dj<=30;dj++)
        {
            if(!di&&!dj) continue;
            for(int i=x;i>=0;i--)
                for(int j=y;j>=0;j--)
                    for(int k=1;k*di<=i&&k*dj<=j;k++)
                        dp[i][j]+=dp[i-k*di][j-k*dj];
        }
    printf("%d\n",dp[x][y]-1);
    return 0;
}
