#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S seoond
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int cnt[65];
int n;
ll a[MAXN];
int t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<60;j++)
                if(a[i]&(1LL<<j)) cnt[j]++;
        ll res=0;
        for(int i=0;i<60;i++) if(cnt[i]%3==1||cnt[i]%3==2) res^=(1LL<<i);
        if(res==0) puts("C");
        else
        {
            bool f=false;
            for(int i=0;i<n;i++)
            {
                bool flag=true;
                if((a[i]^res)>=a[i]) continue;
                for(int j=0;j<60;j++)
                {
                    if(cnt[j]%3==0) continue;
                    if(cnt[j]%3==2&&(a[i]&(1LL<<j))) {flag=false; break;}
                    if(cnt[j]%3==1&&(!(a[i]&(1LL<<j)))) {flag=false; break;}
                }
                if(flag) {f=true; break;}
            }
            if(f) puts("A"); else puts("B");
        }
    }
    return 0;
}
