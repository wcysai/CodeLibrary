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
int T,R,k,a[MAXN];
bool check(int x,int y,int r)
{
    if(4LL*x*x+4LL*y*y>(2LL*R+1)*(2*R+1)) return false;
    if(1LL*x*x+1LL*y*y<=1LL*(r-1)*(r-1)) return false;
    if(1LL*x*x+1LL*y*y>=1LL*r*r) return false;
    int dx=2*x+1,dy=2*y,dr=2*r;
    if(1LL*dx*dx+1LL*dy*dy>=1LL*dr*dr) return false;
    dx=2*x; dy=2*y+1;
    if(1LL*dx*dx+1LL*dy*dy>=1LL*dr*dr) return false;
    dx=2*x-1; dy=2*y; dr=2*(r-1);
    if(1LL*dx*dx+1LL*dy*dy<1LL*dr*dr) return false;
    dx=2*x; dy=2*y-1;
    if(1LL*dx*dx+1LL*dy*dy<1LL*dr*dr) return false;
    return true;
}
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        printf("Case #%d: ",t);
        scanf("%d",&R);
        ll ans=0;
        for(int x=1;x<=R;x++)
            for(int y=x;y<=R;y++)
            {
                int r=(int)sqrt(x*x+y*y);
                while(x*x+y*y>r*r) r++;
                if(check(x,y,r)) { ans+=(x==y?4:8);}
            }
        printf("%lld\n",ans);
    }
    return 0;
}

