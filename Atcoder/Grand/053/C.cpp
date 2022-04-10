#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int ffact[MAXN],invff[MAXN];
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
int solve(int l,int r)
{
    if(l>r) return 1;
    if(l<=1) return ffact[r];
    return 1LL*ffact[r]*invff[l-2]%MOD;
}
int solve_inv(int l,int r)
{
    if(l>r) return 1;
    if(l<=1) return invff[r];
    return 1LL*invff[r]*ffact[l-2]%MOD;
}
int main()
{
    ffact[0]=invff[0]=ffact[1]=invff[1]=1;
    for(int i=2;i<=2000000;i++) ffact[i]=1LL*ffact[i-2]*i%MOD;
    invff[2000000]=pow_mod(ffact[2000000],MOD-2);
    invff[1999999]=pow_mod(ffact[1999999],MOD-2);
    for(int i=1999998;i>=2;i--) invff[i]=1LL*invff[i+2]*(i+2)%MOD;
    scanf("%d",&n);
    int ans=2*n;
    int invn=pow_mod(n,MOD-2);
    for(int i=0;i<=n-1;i++)
    {
        int prob=1LL*solve(i+1,2*n-i-1)*solve_inv(i+2,2*n-i-2)%MOD;
        prob=1LL*prob*invn%MOD;
        dec(ans,prob);
    }
    printf("%d\n",ans);
    return 0;
}