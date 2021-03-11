#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    if(n==1) printf("%d\n",pow_mod(k,m));
    else if(m==1) printf("%d\n",pow_mod(k,n));
    else 
    {
        int ans=0;
        for(int i=1;i<=k;i++) add(ans,1LL*(pow_mod(i,n)-pow_mod(i-1,n)+MOD)*pow_mod(k+1-i,m)%MOD);
        printf("%d\n",ans);
    }
    return 0;
}