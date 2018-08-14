#include<bits/stdc++.h>
#define MAXN 50
#define INF 1000000000000000
using namespace std;
typedef long long ll;
int query;
char str[MAXN];
int main()
{
    scanf("%d",&query);
    int p=0;
    while(query--)
    {
        p++;
        scanf("%s",str);
        int x=strlen(str);
        ll s=0;
        ll a=str[x-3]-'0';
        ll b=str[x-2]-'0';
        ll c=str[x-1]-'0';
        for(int i=0;i<x-3;i++)
            s=s*10+str[i]-'0';
        ll ans=-100;
        ll mod=1;
        ll t=s;
        for(int i=0;i<x-4;i++)
        {
            s=s/10;
            mod=mod*(ll)10;
            ans=max(ans,s+t%mod-a*b/c);
        }
        printf("Case #%d: %lld\n",p,ans);
    }
    return 0;
}
