#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
typedef pair<int,int> P;
int t,n;
struct crd
{
    int x,y,id;
};
bool cmp(crd a,crd b)
{
    if(a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
int det(crd a,crd b)
{
    return a.x*b.y-a.y*b.x;
}
vector<crd> convex_hull(crd* ps,int n)
{
    sort(ps,ps+n,cmp);
    int k=0;
    vector<P> qs(n*2);
    for(int i=0;i<n;i++)
    {
        while(k>1&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++]=ps[i];
    }
    for(int i=n-2,t=k;i>=0;i--)
    {
        while(k>t&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<=0) k--;
        qs[k++]=ps[i];
    }
    qs.resize(k-1);
    return qs;
}
char ans[MAXN];
int qs[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&a[i].x,&a[i].y);
            a[i].id=i;
        }
        if(n<3)
        {
            printf("NO\n");
            continue;
        }
        else if(n==3)
        {
            sort(a,a+n,cmp);
            if((a[1].x-a[0].x)*(a[2].y-a[1].y)==(a[2].x-a[1].x)*(a[1].y-a[0].y))
            {
                printf("YES\n");
                for(int i=0;i<3;i++)
                    ans[id[i]]=i==2?'B':'A';
                printf("%s\n",ans);
            }
            else
                printf("NO\n");
        }
        else
        {
            printf("YES\n");
            for(int i=0;i<n;i++)
                ans[i]='A';
            vector<crd> res=convex_hull(a,4);
            if(res.size()==4)
                ans[res[1].id]=ans[res[2].id]='B';
            else
            {
                for(int i=0;i<4;i++)
                {
                    bool f=false;
                    for(int j=0;j<res.size();j++)
                        if(res[j].id==res[i].id) f=true,break;
                    if(!f) ans[res[i].id]='B',break;
                }
            }
            printf("%s\n",ans);
        }
    }
    return 0;
}
