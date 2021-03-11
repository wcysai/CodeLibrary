#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int K;
int main()
{
    ll ans=0;
    scanf("%d",&K);
    for(int i=1;i<=K;i++)
        for(int j=1;i*j<=K;j++)
            for(int k=1;i*j*k<=K;k++)
                ans++;
    printf("%lld\n",ans);
}