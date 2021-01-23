#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,cnt[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    for(int i=0;i<n;i++) 
    {
        cnt[i]=min(cnt[i],k);
        if(i) cnt[i]=min(cnt[i],cnt[i-1]);
    }
    int ans=0;
    for(int i=0;i<n;i++) ans+=cnt[i];
    printf("%d\n",ans);
    return 0;
}