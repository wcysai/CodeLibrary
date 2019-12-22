#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a[MAXN],b[MAXN];
bool check(int x)
{
    vector<int> v;
    for(int i=1;i<=n;i++) v.push_back((a[i]+x)%m);
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) if(v[i]!=b[i+1]) return false;
    return true;
}
vector<int> vv;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        int d=(b[i]+m-a[1])%m;
        vv.push_back(d);
    }
    sort(vv.begin(),vv.end());
    for(auto d:vv) 
    {
        if(check(d))
        {
            printf("%d\n",d);
            return 0;
        }
    }
    assert(0);
    return 0;
}