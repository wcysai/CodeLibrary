#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 14005
#define MAXK 30005
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef bitset<30005> bs;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
int a[MAXN];
bs dp[MAXN];
vector<int> nodes;
vector<P> ans;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
    if(a[2*n]-a[1]<k) {puts("No"); return 0;}
    int need=a[2*n]-a[1]-k;
    dp[1].set(0);
    for(int i=1;i<2*n;i++)
    {
        if((i%2==0)) dp[i+1]=dp[i]|(dp[i]<<(a[i+1]-a[i]));
        else dp[i+1]=dp[i];
    }
    if(!dp[2*n].test(need)) puts("No");
    else
    {
        puts("Yes");
        int x=2*n,y=need;
        nodes.push_back(x);
        while(x!=0)
        {
            assert(dp[x].test(y));
            if(!dp[x-1].test(y))
            {
                assert((int)nodes.size()%2==0);
                for(int j=0;j<(int)nodes.size()/2;j++) ans.push_back((P(nodes[j],nodes[nodes.size()-1-j])));
                nodes.clear();
                y-=a[x]-a[x-1];
            } 
            x--;
            if(x) nodes.push_back(x);
        }
        assert((int)nodes.size()%2==0);
        for(int j=0;j<(int)nodes.size()/2;j++) ans.push_back((P(nodes[j],nodes[nodes.size()-1-j])));
        for(auto p:ans) printf("%d %d\n",p.S,p.F);
    }
    return 0;
}