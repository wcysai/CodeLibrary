#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],inv[MAXN],coef[MAXN],s[MAXN];
int cnt[MAXN];
int sum[MAXN],res[MAXN];
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
    inv[1]=1;
	for(int i=2;i<=1000000;i++) inv[i]=1LL*(MOD-MOD/i)*inv[MOD%i]%MOD;
    scanf("%d",&n);
    for(int i=1;i<=1000000;i++) coef[i]=inv[i];
    for(int i=1;i<=1000000;i++)
        for(int j=2*i;j<=1000000;j+=i)
            dec(coef[j],coef[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i=1;i<=1000000;i++)
        for(int j=i;j<=1000000;j+=i)
            for(int k=1;k<=cnt[j];k++)
            {
                add(res[i],1LL*j*sum[i]%MOD);
                add(sum[i],j);
            }
    int ans=0;
    for(int i=1;i<=1000000;i++) add(ans,1LL*coef[i]*res[i]%MOD);
    printf("%d\n",ans);
    return 0;
}
