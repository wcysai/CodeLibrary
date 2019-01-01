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
int T,n,m;
vector<int> a,b;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        a.clear();b.clear();
        for(int i=0;i<n;i++)
        {
            int x;scanf("%d",&x);
            a.push_back(x);
        }
        for(int i=0;i<m;i++)
        {
            int x;scanf("%d",&x);
            b.push_back(x);
        }
        sort(a.begin(),a.end());sort(b.begin(),b.end());
        int ans=0;
        for(int i=0;i<n;i++) ans+=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        printf("%d\n",ans);
    }
    return 0;
}

