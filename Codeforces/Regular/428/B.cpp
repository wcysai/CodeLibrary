#include<bits/stdc++.h>
#define MAXN 101
using namespace std;
int n,k,a[MAXN];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++)
        scanf("%d",&a[i]);
    sort(a,a+k,cmp);
    int x=n,y=2*n,z=0;
    for(int i=0;i<k;i++)
    {
        int p=min(a[i]/4,x);
        x-=p;
        a[i]-=4*p;
        if(x==0)
        {
            if(z>0&&a[i]%2==1)
            {
                y-=a[i]/2;
                z--;
            }
            else
            {
                y-=(a[i]+1)/2;
            }
        }
        else
        {
            if(a[i]==3) x--;
            else if(a[i]==2){ if(y>0) y--; else {x--; z++;}}
            else if(a[i]==1) {if(z>0) z--; else if(y>0) y--; else {x--; y++;}}
        }
        if(x<0||y<0||z<0)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
