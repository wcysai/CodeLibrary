#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
struct tic
{
    int time,type,num;
};
bool cmp(tic x,tic y)
{
    if(x.time!=y.time) return x.time<y.time;
    if(x.type!=y.type) return x.type>y.type;
    return x.num<y.num;
}
int n;
tic a[2*MAXN];
int main()
{
    while(scanf("%d",&n)==1)
    {
        if(!n) break;
        for(int i=0;i<n;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            a[2*i].time=x;
            a[2*i+1].time=y;
            a[2*i].type=0;
            a[2*i+1].type=1;
            a[2*i].num=a[2*i+1].num=z;
        }
        sort(a,a+2*n,cmp);
        int ans=0,cnt=0;
        for(int i=0;i<2*n;i++)
        {
            if(a[i].type==0)
            {
                cnt+=a[i].num;
                ans=max(cnt,ans);
            }
            else cnt-=a[i].num;
        }
        printf("%d\n",ans);
    }
    printf("*\n");
    return 0;
}
