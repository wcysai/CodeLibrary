#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,b,k,sx,sy,gx,gy;
ll solve(int dx,int dy)
{
    dx=max(-dx,dx); dy=max(-dy,dy);
    return 1LL*min(dx,dy)*k+max(dx,dy);
}
ll go(int dx,int dy)
{
    dx=max(-dx,dx); dy=max(-dy,dy);
    ll ans=0;
    ans+=dx-dx%b; dx=dx%b;
    ans+=dy-dy%b; dy=dy%b;
    ll res=solve(dx,dy);
    res=min(res,b+solve(dx-b,dy));
    res=min(res,b+solve(dx,dy-b));
    res=min(res,2*b+solve(dx-b,dy-b));
    return res+ans;
}
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&b,&k,&sx,&sy,&gx,&gy);
        ll ans=1LL*k*(max(sx-gx,gx-sx)+max(sy-gy,gy-sy));
        int mod=sx%b;
        ans=min(ans,1LL*mod*k+max(sy-gy,gy-sy)+1LL*k*max(sx-mod-gx,gx-(sx-mod)));
        ans=min(ans,1LL*(b-mod)*k+max(sy-gy,gy-sy)+1LL*k*max(sx+b-mod-gx,gx-(sx+b-mod)));
        mod=sy%b;
        ans=min(ans,1LL*mod*k+max(sx-gx,gx-sx)+1LL*k*max(sy-mod-gy,gy-(sy-mod)));
        ans=min(ans,1LL*(b-mod)*k+max(sx-gx,gx-sx)+1LL*k*max(sy+b-mod-gy,gy-(sy+b-mod)));
        int xmod[2],ymod[2];
        xmod[0]=-(sx%b); xmod[1]=(xmod[0]+b); ymod[0]=-(sy%b); ymod[1]=(ymod[0]+b);
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                ans=min(ans,1LL*max(ymod[j],-ymod[j])*k+max(xmod[i],-xmod[i])+go(gx-(sx+xmod[i]),gy-(sy+ymod[j])));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                ans=min(ans,1LL*max(xmod[i],-xmod[i])*k+max(ymod[j],-ymod[j])+go(gx-(sx+xmod[i]),gy-(sy+ymod[j])));
        printf("%lld\n",ans);
    }
    return 0;
}

