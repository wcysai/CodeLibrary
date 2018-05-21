#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define INF 10000020
using namespace std;
struct node
{
    int x;
    int y;
};
struct node a[25001];
int n,t,b[25001],cnt,endi,s,f,sus;
bool cmp(node m,node n)
{
if(m.x!=n.x) return m.x<n.x;
return m.y>n.y;
}
int main()
{
    fill(b,b+25001,INF);
    scanf("%d %d",&n,&t);
    for(int i=0;i<=n-1;i++)
    {
        scanf("%d %d",&a[i].x,&a[i].y);
        b[i]=a[i].x;
    }
    sort(a,a+n,cmp);
    if(a[0].x!=1)
    {
        printf("-1");
        return 0;
    }
    cnt=1;
    endi=a[0].y;
    s=1;
    while (true)
    {

        sus=endi;
        f=0;

        if (endi>=t) break;
        while(a[s].x<=sus+1&&s<=n-1)
        {
            if(a[s].y>endi)
            {
                endi=a[s].y;
                f=1;
            }
            s++;
        }
        if(f==0)
        {
            printf("-1");
            return 0;
        }
         cnt++;
    }
    printf("%d",cnt);
    return 0;
}