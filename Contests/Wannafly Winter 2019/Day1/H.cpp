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
typedef long double db;
int T,n;
struct sp
{
    db x,y,z,r;
}a[MAXN];
sp SP;
db dist2(sp p,sp q)
{
    return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y)+(p.z-q.z)*(p.z-q.z);
}
const db PI=acos(-1.0);
int main()
{
    scanf("%d",&T);
    int tot=0;
    while(T--)
    {
        printf("Case #%d: ",++tot);
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%Lf%Lf%Lf%Lf",&a[i].x,&a[i].y,&a[i].z,&a[i].r);
        scanf("%Lf%Lf%Lf%Lf",&SP.x,&SP.y,&SP.z,&SP.r);
        db ans=0;
        for(int i=0;i<n;i++)
        {
            int R=SP.r,r=a[i].r;
            db d=sqrt(dist2(SP,a[i]));
            if(d<(R-r)) {ans+=PI*r*r*r*4/3; continue;}
            else if(d>(R+r)) continue;
            else 
            {
                ans+=PI*(R+r-d)*(R+r-d)*(d*d+2*d*r-3*r*r+2*d*R+6*r*R-3*R*R)/12/d;
            }
        }
        printf("%.15Lf\n",ans);
    }
    return 0;
}

