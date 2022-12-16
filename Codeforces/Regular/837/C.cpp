#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
int p,t,n,prime[MAXN],phi[MAXN],miu[MAXN];
bool is_prime[MAXN];
int sieve(int n)
{
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(int j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
int pow_mod(int a,int i,int n)
{
    if(i==0) return 1%n;
    int temp=pow_mod(a,i>>1,n);
      temp=temp*temp%n;
    if(i&1) temp=(long long) temp*a%n;
    return temp;
}
bool test(int n,int a,int d)
{
    if(n==2) return true;
    if(n==a) return true;
    if((n&1)==0) return false;
    while(!(d&1)) d=d>>1;
    int t=pow_mod(a,d,n);
    while((d!=n-1)&&(t!=1)&&(t!=n-1))
    {
        t=(long long)t*t%n;
        d=d<<1;
    }
    return(t==n-1||(d&1)==1);
}
bool isPrime(int n)
{
    if(n<2) return false;
    int a[]={2,3,61};
    for(int i=0;i<=2;++i) if(!test(n,a[i],n-1)) return false;
    return true;
}
map<int,int> mp;
bool factorize(int x)
{
    for(int i=0;i<p;i++)
    {
        if(x==1) break;
        if(x%prime[i]==0)
        {
            while(x%prime[i]==0) x/=prime[i];
            if(mp[prime[i]]) return false; 
            mp[prime[i]]++;
        }
    }
    if(x>1)
    {
        if(mp[x]) return false;
        mp[x]++;
    }
    return true;
}
int main()
{
    p=sieve(40000);
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        scanf("%d",&n);
        bool f=true;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if(f) {if(!factorize(x)) f=false;}
        }
        if(!f) puts("YES"); else puts("NO");
    }
    return 0;
}
