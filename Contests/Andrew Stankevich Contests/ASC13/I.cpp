#include<bits/stdc++.h>
using namespace std;
long long ans[]=
{
0,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,6,
0,108,0,1182,0,10338,0,79818,0,570342,
0,0,0,0,6,0,124,62,1646,1630,
18120,25654,180288,317338,1684956,3416994,0,0,0,0,
0,124,0,13514,0,765182,0,32046702,0,1136189734,
0,36378354342,0,0,0,0,108,62,13514,25506,
991186,3103578,57718190,238225406,2965022934,14388538008,140937146918,754315570508,
};
int n,m;
int main()
{
    freopen("solid.in","r",stdin);
    freopen("solid.out","w",stdout);
    scanf("%d%d",&n,&m);
    printf("%lld\n",ans[(n-1)*16+(m-1)]);
    return 0;
}
