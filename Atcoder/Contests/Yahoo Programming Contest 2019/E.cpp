#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN][MAXN];
int bas[MAXN];
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
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(a[i][j])
            {
                if(!bas[j])
                {
                    bas[j]=i;
                    cnt++;
                    break;
                }
                for(int k=1;k<=m;k++) a[i][k]^=a[bas[j]][k];
            }
        }
    }
    int free=n-cnt,ans=1LL*pow_mod(2,n)%MOD;
    int res=pow_mod(2,free);dec(ans,res);
    ans=1LL*ans*pow_mod(2,m-1)%MOD;
    printf("%d\n",ans);
    return 0;
}

