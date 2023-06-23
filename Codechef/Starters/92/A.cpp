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
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&K);
        int ans=1;
        for(int i=1;i<=N;i++){
            int rem=max(1,K-i+1);
            ans=1LL*ans*rem%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}

