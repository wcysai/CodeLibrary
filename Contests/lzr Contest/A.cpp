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
int n,m,a[MAXN];
int cnt[MAXN],num;
void add(int x) {if(!cnt[x]) num++; cnt[x]++;}
void dec(int x) {if(cnt[x]==1) num--; cnt[x]--;}
int main()
{
    scanf("%d%d",&n,&m);
    ll ans=0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int r=0;
    for(int i=1;i<=n;i++)
    {
        while(r<=n&&num<m) {r++; add(a[r]);}
        if(r==n+1) break;
        ans+=(n-r+1);
        dec(a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}

