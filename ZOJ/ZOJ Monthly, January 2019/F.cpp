#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T,n,m,a[MAXN],b[MAXN],bas1[65],bas2[65];
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&m);
        ll cur=0;
        for(ll i=1;i<=n;i++)
        {
            ll x,y;scanf("%lld%lld",&x,&y);
            cur^=x; a[i]=x^y;
        }
        for(ll i=1;i<=m;i++)
        {
            ll x,y;scanf("%lld%lld",&x,&y);
            cur^=x; b[i]=x^y;
        }
        memset(bas1,0,sizeof(bas1));
        memset(bas2,0,sizeof(bas2));
        for(ll i=1;i<=n;i++)
        {
            ll x=a[i];
            for(int j=60;j>=0;j--)
            {
                if(x&(1LL<<j))
                {
                    if(!bas1[j])
                    {
                        bas1[j]=x;
                        break;
                    }
                    x^=bas1[j];
                }
            }
        }
        for(ll i=1;i<=m;i++)
        {
            ll x=b[i];
            for(int j=60;j>=0;j--)
            {
                if(x&(1LL<<j))
                {
                    if(!bas2[j])
                    {
                        bas2[j]=x;
                        break;
                    }
                    x^=bas2[j];
                }
            }
        }
        for(int j=60;j>=0;j--)
        {
            if(!bas1[j]&&!bas2[j]) continue;
            if(bas1[j]&&!bas2[j]) {if(!(cur&(1LL<<j))) cur=cur^bas1[j]; continue;}
            if(bas2[j]&&!bas1[j]) {if(cur&(1LL<<j)) cur=cur^bas2[j]; continue;}
            if(cur&(1LL<<j))
            {
                cur=cur^bas1[j];
                ll x=bas1[j]^bas2[j];
                bas1[j]=0;
                for(ll k=60;k>=0;k--)
                {
                    if(x&(1LL<<k))
                    {
                        if(!bas1[k])
                        {
                            bas1[k]=x;
                            break;
                        }
                        x^=bas1[k];
                    }
                }
            }
            else 
            {
                ll x=bas1[j]^bas2[j];
                bas1[j]=0;
                for(ll k=60;k>=0;k--)
                {
                    if(x&(1LL<<k))
                    {
                        if(!bas1[k])
                        {
                            bas1[k]=x;
                            break;
                        }
                        x^=bas1[k];
                    }
                }
            }
        }
        printf("%lld\n",cur);
    }
    return 0;
}

