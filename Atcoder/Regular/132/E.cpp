#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define INV2 499122177
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char s[MAXN];
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
int fact[MAXN],invf[MAXN];
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int nfact[MAXN];
vector<int> holes;
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    nfact[0]=1;
    for(int i=1;i<=100000;i++)
        nfact[i]=1LL*(2*i-1)*nfact[i-1]%MOD;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) if(s[i]=='.') holes.push_back(i);
    int sz=(int)holes.size();
    int inv=pow_mod(INV2,sz);
    int ans=0;
    int left=0,right=sz;
    int last=1;
    for(int i=0;i<=sz;i++)
    {
        int l=(i==0?1:holes[i-1]+1),r=(i==sz?n:holes[i]-1);
        for(int j=l;j<=r;j++) if(s[j]=='<') add(ans,1LL*nfact[i]*nfact[sz-i]%MOD*comb(sz,i)%MOD);
        //printf("i=%d l=%d r=%d sz=%d\n",i,l,r,sz);
        add(ans,1LL*nfact[i]*nfact[sz-i]%MOD*(i==0?0:holes[i-1])%MOD*comb(sz,i)%MOD);
    }
    ans=1LL*ans*invf[sz]%MOD;
    ans=1LL*ans*inv%MOD;
    printf("%d\n",ans);
    return 0;
}