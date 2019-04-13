#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> v;
int main()
{
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    scanf("%d",&n);
    int t=1;
    while(t*t<n) t++;
    for(int i=t;i>=1;i--)
    {
        int x=min(t,n-(i-1));
        v.push_back(x);
        n-=x;
    }
    sort(v.begin(),v.end());
    int now=1;
    for(auto x:v)
    {
        for(int j=now+x-1;j>=now;j--)
            printf("%d ",j);
        now+=x;
    }
    return 0;
}
