#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define INV2 500000004
#define INV4 250000002
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,m;
ll n;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%d",&n,&m);
        n=n%(MOD-1);
        int valid=(pow_mod(2,n)-2+MOD)%MOD;
        int all=(1LL*valid*valid%MOD-valid+MOD)*INV2%MOD;
        int tangent=1LL*valid*INV2%MOD;
        int included=((pow_mod(3,n)-3LL*valid-3)%MOD+MOD)%MOD;
        int nointersect=1LL*(1+pow_mod(3,n)-pow_mod(2,n==MOD-1?0:n+1))*INV2%MOD;
        int away=(nointersect-tangent+MOD)%MOD;
        int intersect=((1LL*all-nointersect-included)%MOD+MOD)%MOD;
        printf("%d %d %d %d %d %d %d\n",valid,all,tangent,included,nointersect,away,intersect);
        if(m==2)
        {
            puts("2");
            continue;
        }
        else if(m==3)
        {
            int ans=6LL*valid%MOD;
            printf("%d\n",ans);
            continue;
        }
        else if(m==4)
        {
            int ans=24LL*(tangent+included)%MOD;
            printf("%d\n",ans);
        }
        else if(m==5)
        {
            int matryoshka=pow_mod(4,n);
            dec(matryoshka,2LL*pow_mod(3,n)%MOD); add(matryoshka,pow_mod(2,n)); dec(matryoshka,valid); dec(matryoshka,2LL*included%MOD);
            printf("%d %d\n",matryoshka,intersect);
            int ans=120LL*(matryoshka+intersect)%MOD;
            printf("%d\n",ans);
        }
    }
    return 0;
}

