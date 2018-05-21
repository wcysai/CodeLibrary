#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#define MAXN 100005
using namespace std;
int a,b;
int main()
{
    while(scanf("%d%d",&a,&b)==2)
    {
        if(!a&&!b) break;
        bool f=true;
        for(;;)
        {
            if(a>b) swap(a,b);
            if(b%a==0) break;
            if(b-a>a) break;
            b-=a;
            f=!f;
        }
        if(f) puts("Stan wins");
        else puts("Ollie wins");
    }
    return 0;
}
