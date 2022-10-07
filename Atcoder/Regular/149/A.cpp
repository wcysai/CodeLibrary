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
int n,k,m;
P ans;
void check(int d)
{
    int now=0;
    for(int i=1;i<=n;i++)
    {
        now=(10LL*now+d)%m;
        if(now==0) ans=max(ans,P(i,d));
    }
}
int main()
{
    ans=P(0,0);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=9;i++) check(i);
    if(ans.F==0) {puts("-1"); return 0;}
    for(int i=1;i<=ans.F;i++) printf("%d",ans.S);
    printf("\n");
    return 0;
}

