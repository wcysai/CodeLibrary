#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
using namespace std;
struct Point 
{
    int x, y;
    Point operator -(Point rhs) { return {x-rhs.x, y-rhs.y}; }
    int operator *(Point rhs) { return x*rhs.y-y*rhs.x; }
    int norm() { return x * x + y * y; }
};
Point pt[MAXN];
int n,ans,ii,jj,kk;
void update(int i,int j,int k)
{
    int cur=(pt[i]-pt[j])*(pt[k]-pt[j]);
    if(cur&&abs(cur)<ans) 
    {
        ans=abs(cur);
        ii=i; jj=j; kk=k;
    }
}
int main()
{
    freopen("triangle.in","r",stdin);
    freopen("triangle.out","w",stdout);
    ans=INF;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&pt[i].x,&pt[i].y);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                update(i,j,k);
    printf("%d %d %d\n",ii+1,jj+1,kk+1);
    return 0;
}
