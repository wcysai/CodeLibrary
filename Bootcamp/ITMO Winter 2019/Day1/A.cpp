#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,b,o;
char str[MAXN];
int ffact[MAXN];
vector<int> v,suf;
int fact[MAXN],invf[MAXN];
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
int comb(int n,int k)
{
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    ffact[0]=fact[0]=invf[0]=1;
    for(int i=1;i<=500000;i++) ffact[i]=1LL*ffact[i-1]*(2*i-1)%MOD;
    fact[0]=invf[0]=1;
    for(int i=1;i<=500000;i++) fact[i]=1LL*i*fact[i-1]%MOD;
    invf[500000]=pow_mod(fact[500000],MOD-2);
    for(int i=499999;i>=1;i--) invf[i]=1LL*(i+1)*invf[i+1]%MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str+1);v.clear();suf.clear();
        n=strlen(str+1);
        int cnt=0,last=-1;
        for(int i=1;i<=n;i++)
        {
            int now=str[i]=='O'?0:1;
            if(last==-1) {last=now; cnt=1; continue;}
            if(last==now) cnt++; 
            else
            {
                v.push_back(cnt);
                cnt=1;last=now;
            }
        }
        v.push_back(cnt);
        int sz=(int)v.size();
        if(sz&1)
        {
            int id=(sz-1)/2;
            printf("%d\n",ffact[id]);
            continue;
        }
        suf.resize(sz);
        suf[sz-1]=v[sz-1];
        for(int i=sz-2;i>=0;i--) suf[i]=suf[i+1]+v[i];
        int ans=0,id=sz/2;
        for(int i=0;i<sz;i+=2) add(ans,1LL*(suf[i+1]+1)*ffact[id-1-i/2]%MOD*ffact[i/2]%MOD*comb(id,i/2)%MOD);
        reverse(v.begin(),v.end()); 
        suf.resize(sz);
        suf[sz-1]=v[sz-1];
        for(int i=sz-2;i>=0;i--) suf[i]=suf[i+1]+v[i];
        for(int i=0;i<sz;i+=2) add(ans,1LL*(suf[i+1]+1)*ffact[id-1-i/2]%MOD*ffact[i/2]%MOD*comb(id,i/2)%MOD);
        printf("%d\n",ans);
    }
    return 0;
}

