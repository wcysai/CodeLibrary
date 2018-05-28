#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int x,y,z;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    while(scanf("%d %d %d",&x,&y,&z)==3)
    {
    if(x<y)
    {
        int t=x;
        x=y;
        y=t;
    }
    if((x<z&&y<z)||(z%gcd(x,y)!=0))
    {
        printf("-1");
        continue;
    }
    int cnt=0,save=0;
    while(true)
    {
        save+=x;
        cnt++;
         if(save==z) break;
        if(save>x) cnt++;
        while(save>=y&&save!=z)
        {
            save-=y;
            cnt++;
            if (save==z) break;
            cnt++;
        }
        if (save==z) break;
    }
    int cnt2=0;
    save=0;
     while(true)
    {
        save+=y;
        cnt2++;
        if(save<x) cnt2++;
        if(save==z) break;
        if(save>=x)
        {
            save-=x;
            cnt2++;
             if(save==z) break;
             cnt2+=2;
        }
    }
    printf("%d\n",min(cnt,cnt2));
    }
    return 0;
}
