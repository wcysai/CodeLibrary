#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,a,b,c,d;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int x,y;
        if(a<0&&c>0) x=1; else x=0;
        if(b<0&&d>0) y=1; else y=0;
        if(!x&&!y) puts("5");
        else if(x&&y) puts("8");
        else puts("6");
    }
    return 0;
}
