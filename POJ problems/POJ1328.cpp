#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define MAXN 1020
#define INF 10000
using namespace std;
struct radar
{
    double left;
    double right;
};
   struct radar r[MAXN];
bool cmp(radar m,radar n)
{
    if(m.right!=n.right) return m.right<n.right;
    else return m.left<n.left;
}
int main()
{
    int n,d,x,y,dig,f;
    scanf("%d %d",&n,&d);
    dig=1;
    while(n!=0||d!=0)
    {
        f=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        if(y>d) f=0;
        r[i].left=x-sqrt(d*d-y*y);
        r[i].right=x+sqrt(d*d-y*y);
    }
    if(!f)
    {
         printf("Case %d: -1\n",dig);
         scanf("%d %d",&n,&d);
         dig++;
        continue;
    }
    if(n==1)
    {
        printf("Case %d: 1\n",dig);
        scanf("%d %d",&n,&d);
        dig++;
        continue;
    }
    sort(r,r+n,cmp);
    int k=0,cnt=0;
    int t;
    while(k<n)
    {
        t=k;
        while(r[k].left<=r[t].right)
            k++;
        cnt++;
    }
    printf("Case %d: %d\n",dig,cnt);
    scanf("%d %d",&n,&d);
    dig++;
    }
    return 0;
}