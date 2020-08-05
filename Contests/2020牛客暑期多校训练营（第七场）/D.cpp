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
ll n;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        if(n>100000) puts("Nobody knows it better than me!");
        else
        {
            ll x=(n*(n+1)*(2*n+1))/6;
            int y=(int)sqrt(x);
            bool f=false;
            for(int i=max(0,y-10);i<=y+10;i++) if(1LL*i*i==x) f=true;
            if(f) puts("Fake news!"); else puts("Nobody knows it better than me!");
        }
    }
    return 0;
}