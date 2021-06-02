#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
ll k;
int fa[MAXN];
int tot=1;
void construct(int cur,ll need)
{
    if(need==2) return;
    if(need==3)
    {
        fa[++tot]=cur;
        return;
    }
    if(need&1)
    {
        fa[++tot]=cur;
        fa[++tot]=cur;
        construct(tot,need/2);
    }
    else
    {
        fa[++tot]=cur;
        construct(tot,need-1);
    }
}
int main()
{
    scanf("%lld",&k);
    construct(1,k);
    printf("%d\n",tot);
    for(int i=2;i<=tot;i++) printf("%d %d\n",fa[i],i);
    return 0;
}