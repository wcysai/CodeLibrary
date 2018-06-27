#include<bits/stdc++.h>
#define MAXN 1020
using namespace std;
typedef long long ll;
struct crd
{
    int x1,y1,x2,y2;
}rect[MAXN];
int x[MAXN*2],y[MAXN*2];
bool cover[MAXN*2][MAXN*2];
int n;
int find(int *x,int val,int n)
{
    int L=0,R=n-1;
    while(R>=L)
    {
        int mid=L+(R-L)/2;
        if(x[mid]==val) return mid;
        else if(x[mid]>val) R=mid-1;
        else L=mid+1;
    }
    return -1;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        if(!n) break;
        memset(cover,false,sizeof(cover));
        int num1=0,num2=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d %d",&rect[i].x1,&rect[i].y1,&rect[i].x2,&rect[i].y2);
            x[num1++]=rect[i].x1;
            x[num1++]=rect[i].x2;
            y[num2++]=rect[i].y1;
            y[num2++]=rect[i].y2;
        }
        sort(x,x+num1);
        sort(y,y+num2);
        num1=unique(x,x+num1)-x;
        num2=unique(y,y+num2)-y;
        for(int i=0;i<n;++i)
        {
            int L_x=find(x,rect[i].x1,num1);
            int R_x=find(x,rect[i].x2,num1);
            int L_y=find(y,rect[i].y1,num2);
            int R_y=find(y,rect[i].y2,num2);
            for(int j=L_x;j<R_x;++j)
                for(int k=L_y;k<R_y;++k)
                    cover[j][k]=true;
        }
        ll ans=0;
        for(int i=0;i<num1;++i)
            for(int j=0;j<num2;++j)
                if(cover[i][j])
                    ans+=(x[i+1]-x[i])*(y[j+1]-y[j]);
        printf("%lld\n",ans);
    }
    printf("*\n");
    return 0;
}
