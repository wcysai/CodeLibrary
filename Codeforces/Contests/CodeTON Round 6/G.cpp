#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int cnt[MAXN],need[MAXN],ans[MAXN],zeroes;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int now=2;
        zeroes=1;
        cnt[a[1]]++; need[1]=need[0]=1;
        for(int i=2;i<=n;i++){
            cnt[a[i]]++; zeroes++;

        }
        ans[1]=a[1];
        for(int i=1;i<=n;i++) cnt[a[i]]=0;
        for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
    }
    return 0;
}

