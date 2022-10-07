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
int T,n,q,a[MAXN],b[MAXN],x[MAXN],y[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        int suma=0,sumb=0,sumx=0,sumy=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            add(suma,a[i]); add(sumb,b[i]);
        }
        scanf("%d",&q);
        for(int i=1;i<=q;i++) 
        {
            scanf("%d%d",&x[i],&y[i]);
            add(sumx,x[i]); add(sumy,y[i]);
        }
        for(int i=1;i<=n;i++)
        {
            add(ans,1LL*a[i]*a[i]%MOD*q%MOD);
            add(ans,1LL*b[i]*b[i]%MOD*q%MOD);
            dec(ans,2LL*a[i]*sumx%MOD);
            dec(ans,2LL*b[i]*sumy%MOD);
        }
        for(int i=1;i<=q;i++)
        {
            add(ans,1LL*x[i]*x[i]%MOD*n%MOD);
            add(ans,1LL*y[i]*y[i]%MOD*n%MOD);
        }
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}

