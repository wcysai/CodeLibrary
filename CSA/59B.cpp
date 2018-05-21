#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int g1,g2,p1,p2;
int main()
{
    scanf("%d%d%d%d",&g1,&p1,&g2,&p2);
    int t1=0,t2=0;
    for(int i=0;i<=g1;i++)
        if(floor(((double)i/g1)*100)==p1) {t1=i; break;}
    for(int i=g2;i>=0;i--)
        if(floor(((double)i/g2)*100)==p2) {t2=i; break;}
    printf("%d\n",min(t2-t1,g2-g1));
    return 0;
}
