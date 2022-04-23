#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,t[MAXN],y[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&t[i],&y[i]);
    t[0]=1; y[0]=0;
    ll ans=-INF,sum=0;
    priority_queue<int> pque;
    int limit=k;
    for(int i=n;i>=0;i--)
    {
        if(t[i]==1)
        {
            ans=max(ans,sum+y[i]);
            limit--;
            if(limit<0) break;
            if(pque.size()>limit)
            {
                int x=pque.top(); pque.pop();
                sum+=x;
            }
        }
        else
        {
            if(y[i]<0)
            {
                pque.push(y[i]);
                if(pque.size()>limit)
                {
                    int x=pque.top(); pque.pop();
                    sum+=x;
                }
            }
            else sum+=y[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}

