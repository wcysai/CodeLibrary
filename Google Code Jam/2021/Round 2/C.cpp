#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
int fact[MAXN],invf[MAXN];
int st[MAXN][32];
int pre[MAXN],a[MAXN];
void init(int n,int *arr)
{
    for(int i=n;i>=1;--i)
    {
        st[i][0]=arr[i];
        for(int j=1;j<=20;j++)
        {
            if(i+(1<<j)-1>n) st[i][j]=st[i][j-1];
            else st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
        }
    }
}
int query(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return min(st[l][k],st[r-(1<<k)+1][k]);
}
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
int solve(int l,int r,int d)
{
    if(l>r) return 1;
    int val=query(l,r);
    int cur=r;
    for(int j=20;j>=0;j--)
        if(cur-(1<<j)>=1&&st[cur-(1<<j)+1][j]>val)
            cur-=(1<<j);
    int pos;
    if(st[cur][0]==val) pos=cur; else pos=cur-1;
    //pos=cur+1;
    if(pos>r) return 0;
    if(val!=d+1) return 0;
    int num=r-l+1;
    int lnum=pos-1-l+1;
    return 1LL*comb(num-1,lnum)*solve(l,pos-1,d)%MOD*solve(pos+1,r,d+1)%MOD;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    pre[1]=0;
    for(int i=2;i<=100000;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        init(n,a);
        int ans=solve(1,n,0);
        printf("Case #%d: %d\n",_,ans);
    }
    return 0;
}