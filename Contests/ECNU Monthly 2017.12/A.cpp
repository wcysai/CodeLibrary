#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int p;
int a[MAXN],b[MAXN];
int cnt[4];
int main()
{
    scanf("%d",&p);
    for(int i=0;i<6;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<6;i++)
        scanf("%d",&b[i]);
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            cnt[(a[i]+b[j])%p]++;
    bool f=true;
    for(int i=0;i<p;i++)
        if(cnt[i]!=36/p){f=false; break;}
    if(f) puts("YES"); else puts("NO");
    return 0;
}
