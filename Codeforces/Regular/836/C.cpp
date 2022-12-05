#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x,p[MAXN];
int prime[MAXN],fact[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    fact[1]=1;
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
    sieve(200000);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&x);
        if(n%x) {puts("-1"); continue;}
        for(int i=1;i<=n;i++) p[i]=i;
        p[1]=x; p[n]=1;
        if(x!=n)
        {
            while(!is_prime[n/x])
            {
                int y=fact[n/x];
                p[x]=x*y;
                x=x*y;
            }
            p[x]=n;
        }
        for(int i=1;i<=n;i++) printf("%d%c",p[i],i==n?'\n':' ');
    }
    return 0;
}

