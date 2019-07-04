#include<bits/stdc++.h>
#define MAXN 15
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char str[2][3];
void solve(int mask)
{
    int x=__builtin_popcount(mask);
    if(x<=3) printf("%d\n",x);
    else if(x==4)
    {
        if(mask==15||mask==39||mask==57||mask==60) puts("6");
        else puts("5");
    }
    else if(x==5)
    {
        if(mask==47||mask==61) puts("8"); else puts("12");
    }
    else puts("19");
}
int get_mask()
{
    int tot=0,s=1;
    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
        {
            tot+=(str[i][j]=='*'?1:0)*s;
            s*=2;
        }
    return tot;
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%s",str[0]);
    scanf("%s",str[1]);
    solve(get_mask());
    return 0;
}
