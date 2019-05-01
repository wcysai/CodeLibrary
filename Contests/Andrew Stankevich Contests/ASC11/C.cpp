#include<bits/stdc++.h>
#define MAXN 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define x1 dakds
#define y1 dkosadk
#define x2 fdaosdas
#define y2 kaosdda
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x[MAXN],y[MAXN];
ll b,w;
pair<ll,ll> get_num(int x,int y)
{
    if(x%2==0||y%2==0) return make_pair(1LL*x*y/2,1LL*x*y/2);
    int parity=(1LL*x*y>0?0:1);
    if(parity) return make_pair(1LL*x*y/2,1LL*x*y/2+1);
    else return make_pair(1LL*x*y/2+1,1LL*x*y/2);
}
void process(int x1,int x2,int y)
{
    b+=get_num(x2,y).F; w+=get_num(x2,y).S;
    b-=get_num(x1,y).F; w-=get_num(x1,y).S;
}
int main()
{
    freopen("bw.in","r",stdin);
    freopen("bw.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        x[i]+=INF; y[i]+=INF;
    }
    x[n+1]=x[1]; y[n+1]=y[1];
    for(int i=2;i<=n+1;i++) if(y[i]==y[i-1]) process(x[i-1],x[i],y[i]);
    printf("%lld %lld\n",max(-b,b),max(-w,w));
    return 0;
}
