#include<bits/stdc++.h>
#define MAXN 55
#define MAXM 10005
using namespace std;
int num[MAXM],n,m,t,pack[MAXM];
int main()
{
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        memset(pack,0,sizeof(pack));
        pack[0]=1;
        for(int j=0;j<=m;j++)
            scanf("%d",&num[j]);
        int k=0;
        while(true)
        {
            int p=-1;
            for(int j=0;j<=m;j++)
                if(num[j]>pack[j]) {p=j; break;}
            if(p==-1) break;
            if(k==0) printf("%d",p); else printf(" %d",p);
            for(int j=m;j>=p;j--)
                pack[j]+=pack[j-p];
            k++;
        }
        printf("\n");
    }
    return 0;
}
