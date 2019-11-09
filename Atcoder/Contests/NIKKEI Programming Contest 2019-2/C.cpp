#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int n,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
map<int,int> mpc,mpd;
int perm[MAXN];
bool vis[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        c[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        d[i]=b[i];
    }
    sort(c+1,c+n+1); sort(d+1,d+n+1);
    for(int i=1;i<=n;i++)
    {
        if(c[i]>d[i])
        {
            puts("No");
            return 0;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(c[i]<=d[i-1])
        {
            puts("Yes");
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        mpc[c[i]]=i; mpd[d[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        perm[mpd[b[i]]]=mpc[a[i]];
    }
    memset(vis,false,sizeof(vis));
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            int cur=i;
            do
            {
                vis[cur]=true;
                cur=perm[cur];
            }while(!vis[cur]);
            cnt++;
        }
    }
    if(cnt==1) puts("No"); else puts("Yes");
    return 0;
}
