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
int n,q,p[MAXN];
int cnt[MAXN];
bool mark[MAXN];
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++) 
    {
        scanf("%d",&p[i]);
        cnt[p[i]]++;
    }
    for(int i=0;i<q;i++)
    {
        int m;
        scanf("%d",&m);
        vector<int> v;
        int ans=0;
        for(int j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x); mark[x]=true;
            ans+=(cnt[x]+1);
        }
        for(auto x:v) if(mark[p[x]]) ans-=2;
        for(auto x:v) mark[x]=false;
        printf("%d\n",ans);
    }
    return 0;
}

