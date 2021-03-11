#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int pow_mod(int a,int i,int mod)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%mod;
        a=1LL*a*a%mod;
        i>>=1;
    }
    return s;
}
int a,b,c;
int main()
{
    scanf("%d%d%d",&a,&b,&c);
    if(__gcd(a,10)==1) printf("%d\n",pow_mod(a,pow_mod(b,c,4),10));
    else if(b==1||(b<4&&c==1)) printf("%d\n",pow_mod(a,pow_mod(b,c,4),10));
    else printf("%d\n",pow_mod(a,pow_mod(b,c,4)+4,10));
    return 0;
}