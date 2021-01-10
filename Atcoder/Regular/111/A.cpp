#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
int m;
int pow_mod(int a,ll i,int m)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%m;
        a=1LL*a*a%m;
        i>>=1;
    }
    return s;
}
int main()
{
    scanf("%lld%d",&n,&m);
    int x=pow_mod(10,n,m);
    int res=pow_mod(10,n,m*m);
    res-=x;
    if(res<0) res+=m;
    printf("%d\n",(res/m)%m);
    return 0;
}