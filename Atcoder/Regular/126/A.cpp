#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T;
ll a,b,c;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        ll ans=0;
        ll tmp=min(b/2,c);//433
        ans+=tmp; b-=2*tmp; c-=tmp;
        tmp=min(a/2,b/2);//2233
        ans+=tmp; a-=2*tmp; b-=2*tmp;
        tmp=min(a,c/2);//442
        ans+=tmp; a-=tmp; c-=2*tmp;
        tmp=min(a/3,c);//4222
        ans+=tmp; a-=3*tmp; c-=tmp;
        ans+=a/5;
        printf("%lld\n",ans);
    }
    return 0;
}