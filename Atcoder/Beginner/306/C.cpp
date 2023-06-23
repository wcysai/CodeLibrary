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
int n,k,a[MAXN];
vector<int> v[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=3*n;i++){
        scanf("%d",&a[i]);
        v[a[i]].push_back(i);
    }
    vector<P> vv;
    for(int i=1;i<=n;i++){
        vv.push_back(P(v[i][1],i));
    }
    sort(vv.begin(),vv.end());
    for(int i=0;i<n;i++) printf("%d ",vv[i].S);
    return 0;
}

