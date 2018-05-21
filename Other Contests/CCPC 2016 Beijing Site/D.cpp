#include<bits/stdc++.h>
#define MAXN 205
using namespace std;
int n,a[MAXN];
int main()
{
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[n+i]=a[i];
        }
        int ans=0,cnt=0;
        bool f=true;
        for(int i=1;i<2*n;i++)
        {
            if(a[i]<a[i-1]) {if(f) cnt++; else {f=true; cnt=1;}}
            else if(a[i]>a[i-1]) {if(!f) cnt++; else {f=false; cnt=1;}}
            else cnt=0;
            ans=max(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}
