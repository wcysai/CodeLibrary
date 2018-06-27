#include<bits/stdc++.h>
#define MAXN 100
using namespace std;
typedef long long ll;
ll h[MAXN],b[MAXN],a[MAXN],mi[MAXN];
int main()
{
    h[0]=2;
    h[1]=3;
    h[2]=6;
    for(int i=3;i<=15;i++)
        h[i]=4*h[i-1]+17*h[i-2]-12*h[i-3]-16;
    mi[0]=1;
    for(int i=1;i<=10;i++)
        mi[i]=4*mi[i-1];
    for(int i=1;i<=10;i++)
        b[i]=3*h[i]*h[i+1]+9*h[i+1]*h[i-1]+9*h[i]*h[i]+27*h[i]*h[i-1]-18*h[i+1]-126*h[i]-81*h[i-1]+192;
    for(int i=1;i<=10;i++)
        a[i]=b[i]+mi[i];
    for(int i=1;i<=10;i++)
        printf("h[%d]=%I64d b[%d]=%I64d a[%d]=%I64d sqrt_a[%d]=%d\n",i,h[i],i,b[i],i,a[i],i,(int)sqrt(a[i]));
    return 0;
}
