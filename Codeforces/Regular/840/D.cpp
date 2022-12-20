#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,i,j,x,y;
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
int fact[MAXN],invf[MAXN];
int comb(int n,int k)
{
    if(n<k) return 0;
    assert(n>=0&&k>=0);
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int calc(int id)
{
    if(i==id) 
    {
        if(x!=n) return 0;
        int len=j-id-1,wid=n-y-1;
        int way=1LL*comb(wid,len);
        return 1LL*way*comb(y-1,n-j)%MOD;
    }
    if(j==id)
    {
        if(y!=n) return 0;
        int len=id-i-1,wid=n-x-1;
        int way=comb(wid,len);
        return 1LL*way*comb(x-1,i-1)%MOD;
    }
    if(x==n||y==n) return 0;
    int t1=(i<id?0:1),t2=(j<id?0:1);
    if(t1^t2)
    {
        int len1=id-i-1,wid1=n-x-1;
        int len2=j-id-1,wid2=n-y-1;
        if(len1+len2<n-max(x,y)-1) return 0;
        if(x<y) return 1LL*comb(y-x-1,len1-(n-y-1-len2))*comb(x-1,i-1)%MOD*comb(n-y-1,len2)%MOD;
        return 1LL*comb(x-y-1,len1-(n-x-1-len2))*comb(y-1,n-j)%MOD*comb(n-x-1,len1)%MOD;
    }
    if(i<id)
    {
        if(x>y) return 0;
        int len1=i-1,len2=j-i-1,len3=id-j-1;
        return 1LL*comb(n-y-1,len3)*comb(y-x-1,len2)%MOD*comb(x-1,len1)%MOD;
    }
    else 
    {
        if(x<y) return 0;
        int len1=i-id-1,len2=j-i-1,len3=n-j;
        return 1LL*comb(n-x-1,len1)*comb(x-y-1,len2)%MOD*comb(y-1,len3)%MOD;
    }
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100]=pow_mod(fact[100],MOD-2);
    for(int i=99;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d%d",&n,&i,&j,&x,&y);
        int ans=0;
        for(int k=2;k<=n-1;k++) add(ans,calc(k));
        printf("%d\n",ans);
    }
    return 0;
}

