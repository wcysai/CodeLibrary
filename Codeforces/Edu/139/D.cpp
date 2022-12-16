#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 10000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int prime[MAXM],fact[MAXM];
bool is_prime[MAXM];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    fact[1]=1;
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
    sieve(10000000);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(__gcd(x,y)!=1) {puts("0"); continue;}
        if(x>y) swap(x,y);
        int d=y-x;
        if(d==1) {puts("-1"); continue;}
        int ans=INF;
        while(d!=1)
        {
            ans=min(ans,fact[d]-x%fact[d]);
            d/=fact[d];
        }
        printf("%d\n",ans);
    }
    return 0;
}

