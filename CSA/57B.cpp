#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll n,k;
char str[MAXN];
ll pre,suf;
int main()
{
    scanf("%lld%lld",&n,&k);
    getchar();
    scanf("%s",str);
    ll x=strlen(str);
    pre=suf=0;
    ll cnt=0,ans=0;
    for(int i=0;i<x;i++)
        if(str[i]=='0') pre++; else break;
    for(int i=x-1;i>=0;i--)
        if(str[i]=='0') suf++; else break;
    for(int i=0;i<x;i++)
        if(str[i]=='0') {cnt++; ans=max(ans,cnt);} else cnt=0;
    if(pre==x) printf("%lld\n",n*k);
    else if(k>1) printf("%lld\n",max(ans,suf+pre));
    else printf("%lld\n",ans);
    return 0;
}

