#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q,a[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d%d",&n,&q);
    multiset<int> ms;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++; ms.insert(a[i]);
    }
    for(int i=1;i<=q;i++)
    {
        int k,l;
        scanf("%d%d",&k,&l);
        ms.erase(ms.find(a[k])); cnt[a[k]]--;
        a[k]=l;
        ms.insert(a[k]); cnt[a[k]]++;
        int maxi=*(--ms.end());
        int sum=0;
        for(int i=max(1,maxi-20);i<=maxi;i++)
        {
            sum+=cnt[i];
            if(i!=maxi) sum/=2;
        }
        int ans=maxi;
        while(sum>=2) sum/=2,ans++;
        printf("%d\n",ans);
    }
    return 0;
}

