#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
ll n,m,k,q,cnt[MAXN];
ll mp[MAXN][MAXN],ans[MAXN][MAXN],res[MAXN][MAXN],f[MAXN];
bool used[MAXN];
void add(ll h1,ll w1,ll h2,ll w2)
{
    if(h1>h2) return;
    ans[h1][w2]++;
    ans[h2+1][w2]--;
}
int main() 
{
    scanf("%lld%lld%lld%lld", &n, &m, &k, &q);
    swap(n,m);
    for(ll i=0;i<k;i++) 
    {
        ll x1,y1,x2,y2;
        scanf("%lld%lld%lld%lld", &x1, &x2, &y1, &y2);
        x1++;x2++;y1++;y2++;
        ll t=x1;x1=n+1-y1;y1=t;
        t=x2;x2=n+1-y2;y2=t;
        x2++;y2--;
        swap(x1,x2);
        //printf("%lld %lld %lld %lld\n", x1, y1, x2, y2);
        mp[x1][y1]++;mp[x2+1][y1]--;mp[x1][y2+1]--;mp[x2+1][y2+1]++;
    }
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            mp[i][j]+=mp[i][j-1];
    for (ll i=1;i<=m;i++)
        for (ll j=1;j<=n;j++)
            mp[j][i]+=mp[j-1][i];
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            if(mp[i][j]>0) mp[i][j]=1;
    memset(cnt,0,sizeof(cnt));
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
            if (mp[i][j]==0) f[j]++; else f[j]=0;
        for(ll j=1;j<=m;j++) cnt[j]=f[j];
        puts("");
        ll t=0,st[MAXN];
        st[0]=0;
        for(ll j=1;j<=m;j++)
        {
            bool f=false;
            while(t>0&&cnt[st[t]]>cnt[j]) 
            {
                //printf("%lld %lld\n",t,st[t]);
                if(cnt[st[t-1]]>cnt[j])
                {
                    add(cnt[st[t-1]]+1,1,cnt[st[t]],j-st[t]);
                    //printf("%lld-%lld %lld\n",cnt[st[t-1]]+1,cnt[st[t]],j-st[t]);
                    t--;
                }
                else
                {
                    add(cnt[j]+1,1,cnt[st[t]],j-st[t]);
                    //printf("%lld-%lld %lld\n",cnt[j]+1,cnt[st[t]],j-st[t]);
                    cnt[st[t]]=cnt[j];
                    f=true;
                    break;
                }
            }
            if(!f) st[++t]=j;
        }
        while(t>0)
        {
            //printf("%lld-%lld %lld\n",cnt[st[t-1]]+1,cnt[st[t]],m+1-st[t]);
            add(cnt[st[t-1]]+1,1,cnt[st[t]],m+1-st[t]);
            t--;
        }
    }
    for(ll i=1;i<=m;i++)
        for(ll j=1;j<=n;j++)
            ans[j][i]+=ans[j-1][i];
    for(ll i=1;i<=n;i++)
        for(ll j=m;j>=1;j--)
            ans[i][j]+=ans[i][j+1]; 
    for(ll i=1;i<=n;i++)
        for(ll j=m;j>=1;j--)
            ans[i][j]+=ans[i][j+1];
    for(ll i=1;i<=q;i++)
    {
        ll x,y;
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",ans[y][x]);
    }
    return 0;
}
