#include<bits/stdc++.h>
#define MAXN 10000005
#define INF 1000000000
#define MOD 104857601
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int n,m;
int fact[MAXN],invf[MAXN];
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
int comb(int n,int k)
{
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int get_ans(P x,P y)
{
    if(x.F>y.F||x.S>y.S) return -1;
    return comb(y.S-x.S+y.F-x.F,y.F-x.F);
}
P mir(P p,int which)
{
    if(!which) return P(p.S+1,p.F-1);
    else return P(p.S-(m-n+1),p.F+(m-n+1));
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=10000000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[10000000]=pow_mod(fact[10000000],MOD-2);
    for(int i=9999999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d",&m,&n);
    int ans=get_ans(P(1,1),P(n,m));
    for(int i=0;i<2;i++)
    {
        P cur=P(1,1);
        int j=i;
        while(true)
        {
            cur=mir(cur,j); j^=1;
            int res=get_ans(cur,P(n,m));
            if(res==-1) break;
            if(i^j) dec(ans,res); else add(ans,res);
        }
    }
    printf("%d\n",ans);
    return 0;
}