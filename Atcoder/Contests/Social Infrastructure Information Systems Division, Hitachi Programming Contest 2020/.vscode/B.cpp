#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,q;
int a[MAXN],b[MAXN];
string str;
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
    scanf("%d%d%d",&n,&m,&q);
    int ans=INF;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    for(int i=0;i<q;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        ans=min(ans,a[u]+b[v]-w);
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    ans=min(ans,a[1]+b[1]);
    printf("%d\n",ans);
    return 0;
}