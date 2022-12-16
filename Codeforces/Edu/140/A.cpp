#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,x[MAXN],y[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<3;i++) scanf("%d%d",&x[i],&y[i]);
        bool xs=(x[0]==x[1]||x[1]==x[2]||x[0]==x[2]);
        bool ys=(y[0]==y[1]||y[1]==y[2]||y[0]==y[2]);
        if(xs&&ys) puts("NO"); else puts("YES");
    }
    return 0;
}

