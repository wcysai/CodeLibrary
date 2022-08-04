#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 6000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
ll a[MAXN];
int p2[MAXN];
int bas[61],cnt[61];
int tot=1,trie[MAXM][2];
void ins(ll x)
{
    int cur=1;
    for(int i=60;i>=0;i--)
    {
        int y=((x>>i)&1);
        if(!trie[cur][y]) trie[cur][y]=++tot;
        cur=trie[cur][y];
    }
}
int main()
{
    p2[0]=1;
    for(int i=1;i<=100000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d",&n);
    tot=1;
    for(int i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        ins(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int cur=1,cnt=0;
        for(int j=60;j>=0;j--)
        {
            int y=((a[i]>>j)&1);
            if(trie[cur][y^1]) cnt++;
            cur=trie[cur][y];
        }
        printf("%d%c",p2[n-cnt],i==n?'\n':' ');
    }
    return 0;
}

