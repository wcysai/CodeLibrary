#include<bits/stdc++.h>
using namespace std;
bool pld(int x)
{
    int d=0,t=x;
    while(x>0)
    {
        d=d*10+x%10;
        x/=10;
    }
    return (d==t);
}
int main()
{
    int ans=0;
    for(int i=100;i<=999;i++)
        for(int j=100;j<=999;j++)
            if(pld(i*j)) ans=max(ans,i*j);
    printf("%d\n",ans);
    return 0;
}
