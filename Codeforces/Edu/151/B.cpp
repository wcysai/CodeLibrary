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
int t,xa,ya,xb,yb,xc,yc;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d",&xa,&ya,&xb,&yb,&xc,&yc);
        int ans=1;
        if(xa<=xb&&xa<=xc) ans+=min(xb,xc)-xa;
        if(xa>=xb&&xa>=xc) ans+=xa-max(xb,xc);
        if(ya<=yb&&ya<=yc) ans+=min(yb,yc)-ya;
        if(ya>=yb&&ya>=yc) ans+=ya-max(yb,yc);
        printf("%d\n",ans);
    }
    return 0;
}

