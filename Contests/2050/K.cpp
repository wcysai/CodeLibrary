/*************************************************************************
    > File Name: K.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-25 14:59:48
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,MAXI,MINI,MEAN,MED;
int abx(int x) {
    return max(-x,x);
}
int main()
{
    scanf("%d",&t);
    int kase=0;
    while(t--)
    {
        kase++;
        scanf("%d%d%d%d",&MINI,&MAXI,&MEAN,&MED);
        printf("Case #%d: ",kase);
        if(MINI>MAXI||MEAN<MINI||MEAN>MAXI||MED<MINI||MED>MAXI||(MINI!=MAXI&&MEAN==MINI)||(MINI!=MAXI&&MEAN==MAXI))
        {
            puts("IMPOSSIBLE");
            continue;
        }
        int ans=INF;
        if(MINI==MAXI) 
        {
            puts("1");
            continue;
        }
        if(MEAN*2==MINI+MAXI&&MED*2==MINI+MAXI)
        {
            puts("2");
            continue;
        }
        if(MED+MAXI<=2*MEAN||MED+MINI>=2*MEAN)
        {
            puts("IMPOSSIBLE");
            continue;
        }
        if(MINI+MAXI+MED==3*MEAN)
        {
            puts("3");
            continue;
        }
        if(MINI+MAXI+2*MED==4*MEAN)
        {
            puts("4");
            continue;
        }
        if(MINI+MAXI+MED>3*MEAN)
        {
            int needed=abx(MINI+MAXI+MED-3*MEAN);
            int inc=abx(MINI-MEAN+MED-MEAN);
            ans=min(ans,3+2*((needed-1)/inc+1));
        }
        else
        {
            int needed=abx(MINI+MAXI+MED-3*MEAN);
            int inc=abx(MAXI-MEAN+MED-MEAN);
            ans=min(ans,3+2*((needed-1)/inc+1));
        }
        if(MINI+MAXI+2*MED>4*MEAN)
        {
            int needed=abx(MINI+MAXI+2*MED-4*MEAN);
            int inc=abx(MINI-MEAN+MED-MEAN);
            ans=min(ans,4+2*((needed-1)/inc+1));
        }
        else
        {
            int needed=abx(MINI+MAXI+2*MED-4*MEAN);
            int inc=abx(MAXI-MEAN+MED-MEAN);
            ans=min(ans,4+2*((needed-1)/inc+1));
        }
        printf("%d\n",ans==INF?-1:ans);
    }
    return 0;
}

