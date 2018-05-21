#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int prime[MAXN];
bool is_prime[MAXN];
bool used[50000000];
int sum[MAXN];
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
int main()
{
    int p=sieve(MAXN-1);
    memset(sum,0,sizeof(sum));
    memset(used,false,sizeof(used));
    for(int i=1;i<MAXN;i++)
        sum[i]=is_prime[i]?sum[i-1]+1:sum[i-1];
    int p1=sum[7100],p2=sum[400],p3=sum[90];
    int ans=0;
    for(int i=0;i<p1;i++)
        for(int j=0;j<p2;j++)
            for(int k=0;k<p3;k++)
            {
                int res=prime[i]*prime[i]+prime[j]*prime[j]*prime[j]+prime[k]*prime[k]*prime[k]*prime[k];
                if(res>=50000000) continue;
                if(!used[res]) ans++;
                used[res]=true;
            }
    printf("%d\n",ans);
    return 0;
}

