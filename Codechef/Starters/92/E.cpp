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
int T,N,K,a[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&K);
        set<int> s;
        for(int i=1;i<=N;i++) {
            scanf("%d",&a[i]);
            s.insert(a[i]);
        }
        int num=(int)s.size();
        printf("%lld\n",1LL*K*max(0,(N+1)/2-num));
    }
    return 0;
}

