#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T;
int prime[MAXN],fact[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) {prime[p++]=i; fact[i]=i;}
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            fact[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int main()
{
    sieve(1000000);
    scanf("%d",&T);
    while(T--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int ans=1;
        while(x>1) {x/=fact[x]; ans=1LL*ans*y%MOD;}
        printf("%d\n",ans);
    }
    return 0;
}