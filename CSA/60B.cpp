#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
int n,e1,e2;
int a[MAXN],b[MAXN];
int ans=0,cnt=0;
int main()
{
    scanf("%d%d%d",&n,&e1,&e2);
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
    for(int i=0;i<n;i++)
        if((a[i]<=e1&&b[i]<=a[i])||(a[i]<=e2&&b[i]<=a[i])) cnt++;
    ans=max(ans,cnt);
    cnt=0;
    for(int i=0;i<n;i++)
        if((a[i]<=e1&&b[i]<=a[i])||(a[i]>=e2&&b[i]>=a[i])) cnt++;
    ans=max(ans,cnt);
    cnt=0;
    for(int i=0;i<n;i++)
        if((a[i]>=e1&&b[i]>=a[i])||(a[i]<=e2&&b[i]<=a[i])) cnt++;
    ans=max(ans,cnt);
    cnt=0;
    for(int i=0;i<n;i++)
        if((a[i]>=e1&&b[i]>=a[i])||(a[i]>=e2&&b[i]>=a[i])) cnt++;
    ans=max(ans,cnt);
    printf("%d\n",ans);
    return 0;
}

