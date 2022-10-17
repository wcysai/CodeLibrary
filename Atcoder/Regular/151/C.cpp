#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
ll n;
int m;
vector<P> v;
int sg[3][MAXN];
bool tmp[64];
int solve()
{
    int now=0;
    while(tmp[now]) now++;
    return now;
}
int main()
{
    /*sg[2][1]=1;
    sg[1][1]=0;
    sg[0][1]=1;
    for(int i=2;i<=100;i++)
    {
        //same
        memset(tmp,false,sizeof(tmp));
        for(int j=2;j<=i-1;j++) tmp[sg[0][j-1]^sg[0][i-j]]=true;
        for(int j=1;j<=i;j++) tmp[sg[1][j-1]^sg[1][i-j]]=true;
        sg[0][i]=solve();
        //dif
        memset(tmp,false,sizeof(tmp));
        for(int j=2;j<=i;j++) tmp[sg[0][j-1]^sg[1][i-j]]=true;
        sg[1][i]=solve();
        //single
        memset(tmp,false,sizeof(tmp));
        for(int j=2;j<=i;j++) tmp[sg[0][j-1]^sg[2][i-j]]=true;
        for(int j=1;j<=i;j++) tmp[sg[1][j-1]^sg[2][i-j]]=true;
        sg[2][i]=solve();
    }
    puts("same");
    for(int i=1;i<=64;i++) printf("%d %d\n",i,sg[0][i]);
    puts("dif");
    for(int i=1;i<=64;i++) printf("%d %d\n",i,sg[1][i]);
    puts("single");
    for(int i=1;i<=64;i++) printf("%d %d\n",i,sg[2][i]);*/
    scanf("%lld%d",&n,&m);
    if(!m)
    {
        if(n&1) puts("Takahashi");
        else puts("Aoki");
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        ll x; int y;
        scanf("%lld%d",&x,&y);
        v.push_back(make_pair(x,y));
    }
    ll sg=0;
    for(int i=1;i<(int)v.size();i++)
    {
        sg^=(v[i].S==v[i-1].S?1:0);
    }
    sg^=(v[0].F-1);
    sg^=(n-v.back().F);
    if(sg) puts("Takahashi"); else puts("Aoki");
    return 0;
}

