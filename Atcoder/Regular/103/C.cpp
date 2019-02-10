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
int n,k,a[MAXN];
int cnt1[MAXN],cnt2[MAXN];
vector<P> v1,v2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
    for(int i=1;i<=n;i+=2) cnt1[a[i]]++;
    for(int i=2;i<=n;i+=2) cnt2[a[i]]++;
    for(int i=1;i<=100000;i++) v1.push_back(P(cnt1[i],i));
    for(int i=1;i<=100000;i++) v2.push_back(P(cnt2[i],i));
    sort(v1.begin(),v1.end(),greater<>());
    sort(v2.begin(),v2.end(),greater<>());
    int ans=v1[0].F+v2[0].F;
    if(v1[0].S==v2[0].S) ans=max(v1[0].F+v2[1].F,v1[1].F+v2[0].F);
    printf("%d\n",n-ans);
    return 0;
}

