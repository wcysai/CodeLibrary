#include<bits/stdc++.h>
#define MAXN 2000305
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int prime[MAXN];
bool is_prime[MAXN];
bool used[MAXN];
int pow10[]={1,10,100,1000,10000,100000,1000000};
int count_digit(int x)
{
    int cnt=0;
    while(x>0)
    {
        x=x/10;
        cnt++;
    }
    return cnt;
}
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
    int p=sieve(1000005);
    memset(used,false,sizeof(used));
    int ans=0;
    for(int i=2;i<1000000;i++)
    {
        if(used[i]) continue;
        bool f=true;
        int t=i,digit=count_digit(i);
        do
        {
            used[t]=true;
            if(!prime[t]) f=false;
            t=(t%10)*pow10[digit]+t/10;
            //printf("%d\n",t);
        }while(t!=i);
        if(f) ans+=digit;
    }
    printf("%d\n",ans);
    return 0;
}

