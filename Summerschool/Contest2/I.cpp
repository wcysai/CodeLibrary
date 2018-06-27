#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int prime[MAXN];
bool is_prime[MAXN];
int n,t,a[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
        }
    }
    return p;
}
int mu[MAXN];
void getMu()
{
    for(int i=1;i<MAXN;i++)
    {
        int target=i==1?1:0;
        int delta=target-mu[i];
        mu[i]=delta;
        for(int j=i+i;j<MAXN;j+=i)
            mu[j]+=delta;
    }
    return;
}
int main()
{
    scanf("%d",&t);
    getMu();
    for(int i=1;i<=30;i++)
    {
        printf("Mu(%d)=%d\n",i,mu[i]);
    }
    for(int k=0;k<t;k++)
    {
        scanf("%d",&n);
        int x=INF;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            x=min(x,a[i]);
        }
        int num=sieve(x);
        ll c=0,s;
        for(int i=0;i<num;i++)
        {
            s=1;
            for(int j=0;j<n;j++)
            s=s*(a[j]/prime[i])%MOD;
            c=(c+s)%MOD;
        }
        printf("Case #%d: %I64d\n",k+1,c);
    }
    return 0;
}
