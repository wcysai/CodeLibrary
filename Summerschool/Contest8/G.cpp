#include<bits/stdc++.h>
#define MAXN 1000
using namespace std;
int t,m,n;
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        int k,p;
        int x,y,z;
        int ans=0;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d %d %d",&x,&y,&z);
            if((x+y+n+m)%2==1) ans^=z;
        }
        scanf("%d",&x);
        for(int j=0;j<x;j++)
            scanf("%d %d",&y,&z);
        scanf("%d",&x);
        for(int j=0;j<x;j++)
            scanf("%d %d",&y,&z);
        if(ans==0) printf("lose\n"); else printf("win\n");
    }
}
