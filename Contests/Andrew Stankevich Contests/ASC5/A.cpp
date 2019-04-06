#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,t;
int phi[MAXN];
int pow_mod(int a,int i,int mod)
{
    int s=1%mod;
    while(i)
    {
        if(i&1) s=1LL*s*a%mod;
        a=1LL*a*a%mod;
        i>>=1;
    }
    return s;
}
int get_res(int mod,int iter=-1)
{
    if(mod==1) return 0;
    if(iter==1) return 2%mod;
    else if(iter==2) return 4%mod;
    else if(iter==3) return 16%mod;
    else if(iter==4) return 65536%mod;
    return pow_mod(2,get_res(phi[mod],iter==-1?-1:iter-1)+phi[mod],mod);
}
int ackermann(int n,int m)
{
    if(n==1) return 2*m%t;
    if(n==2) return pow_mod(2,m,t);
    return get_res(t,m);
}

int main()
{
    freopen("ackerman.in","r",stdin);
    freopen("ackerman.out","w",stdout);
    for(int i=1;i<=100;i++)
        for(int j=1;j<=i;j++)
            if(__gcd(i,j)==1) phi[i]++;
    scanf("%d",&t);
    int i=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n&&!m) break;
        printf("Case %d: ",++i);
        if(n<=3) printf("%d\n",ackermann(n,m));
        else if(m==1) printf("%d\n",2%t);
        else if(m==2) printf("%d\n",4%t);
        else if(n==4&&m==3) printf("%d\n",65536%t);
        else printf("%d\n",get_res(t));
    }
    return 0;
}
