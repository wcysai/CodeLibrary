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
int n,k,a[MAXN];
void solve(int x)
{
    vector<int> v;
    for(int i=x;i<n;i+=k) v.push_back(a[i]);
    sort(v.begin(),v.end());
    int now=0;
    for(int i=x;i<n;i+=k) a[i]=v[now++];
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<k;i++) solve(i);
    bool f=true;
    for(int i=0;i<n-1;i++) if(a[i]>a[i+1]) f=false;
    if(f) puts("Yes"); else puts("No");
    return 0;
}

