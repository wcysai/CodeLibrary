#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,m;
ll n;
ll cnt[70];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%d",&n,&m);
        for(int i=0;i<=60;i++) cnt[i]=0;
        ll sum=0;
        for(int i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            for(int j=0;j<30;j++)
                if(x&(1<<j)) cnt[j]++;
            sum+=x;
        }
        if(sum<n)
        {
            puts("-1");
            continue;
        }
        int ans=0;
        for(int i=60;i>=0;i--)
        {
            if(n&(1LL<<i))
            {
                ll need=1;
                for(int j=i;j>=0;j--)
                {
                    need-=min(cnt[j],need);
                    need=need*2;
                }
                if(need==0)
                {
                    for(int j=i;j>=0;j--)
                    {
                        ll used=min(cnt[j],need); cnt[j]-=used;
                        need-=used;
                        need=need*2;
                    }
                    n-=(1LL<<i);
                }
                else
                {
                    for(int j=1+1;j<=60;j++)
                    {
                        if(cnt[j])
                        {
                            ans+=j-i;
                            cnt[i]+=(1LL<<(j-i));
                            cnt[i]--;
                        }
                    }
                }
                
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}