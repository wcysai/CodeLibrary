#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1100000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
vector<int> v;
int check(int x)
{
    int smaller=upper_bound(v.begin(),v.end(),x)-v.begin();
    return x+1-smaller;
}
int solve(int k)
{
    int l=-1,r=INF;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(check(mid)>=k) r=mid; else l=mid;
    }
    return r;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<q;i++)
    {
        int k;
        scanf("%d",&k);
        printf("%d ",solve(k));
    }
    return 0;
}

