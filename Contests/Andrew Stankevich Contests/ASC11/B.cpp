#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll ans[]={
1,0,1,0,1,0,1,0,1,1,
4,5,12,15,30,37,1,3,13,32,
97,214,549,1144,1,7,41,162,691,2255,
8197,24790,1,15,125,770,4627,21928,111158,478500,
1,31,374,3537,30191,206521,1466264,8947384,1,63,
1105,15897,193255,1897387,18898328,162815499,1,127,3238,70500,
1222265,17168439,240144512,2914401494LL,
};
int n,m;
int main()
{
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    scanf("%d%d",&m,&n);
    printf("%lld\n",ans[(m-1)*8+n-1]);
    return 0;
}
