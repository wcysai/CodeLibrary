#include<bits/stdc++.h>
#define MAXN 20
using namespace std;
int n,k;
char str[MAXN];
int main()
{
    while(scanf("%s",str)==1)
    {
        int id=0,a=0,b=0,aleft=5,bleft=5;
        bool f=true;
        while(id<10)
        {
            if(id&1)
            {
                bleft--;
                if(str[id]=='1') b++;
            }
            else
            {
                aleft--;
                if(str[id]=='1') a++;
            }
            if(a>b+bleft)
            {
                f=false;
                printf("TEAM-A %d\n",id+1);
                break;
            }
            if(b>a+aleft)
            {
                f=false;
                printf("TEAM-B %d\n",id+1);
                break;
            }
            id++;
        }
        if(!f) continue;
        for(int i=0;i<5;i++)
        {
            if(str[10+i*2]!=str[11+i*2])
            {
                f=false;
                if(str[10+i*2]=='1') printf("TEAM-A %d\n",12+i*2); else printf("TEAM-B %d\n",12+i*2);
                break;
            }
        }
        if(f) printf("TIE\n");
    }
    return 0;
}
