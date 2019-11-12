#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int T,n,m;
vector<int> G[MAXN];
vector<P> ans;
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        ans.clear();
        scanf("%d%d",&n,&m);
        bool swapped=(n>m); if(n>m) swap(n,m);
        if(n==2&&m<=4) {printf("Case #%d: IMPOSSIBLE\n",t); continue;}
        if(n==3&&m==3) {printf("Case #%d: IMPOSSIBLE\n",t); continue;}
        if(n==2)
        {
            for(int i=1;i<=m;i++) ans.push_back(P(1,i)),ans.push_back(P(2,(i+3>m?i+3-m:i+3)));
        }
        else
        {
            if(n==m&&(n%2==0))
            {
                for(int i=1;i<=m;i++)
                {
                    int pos=(i==1?m:i-1);
                    for(int j=1;j<=n;j++)
                    {
                        if(j&1) ans.push_back(P(j,pos));
                        else ans.push_back(P(j,pos+2>m?pos+2-m:pos+2));
                    }
                }
            }
            else
            {
                for(int i=1;i<=m;i++)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(j&1) ans.push_back(P(j,i));
                        else ans.push_back(P(j,i+2>m?i+2-m:i+2));
                    }
                }
            }
        }
        if(swapped) {for(auto &p:ans) swap(p.F,p.S); swap(n,m);}
        /*assert((int)ans.size()==n*m);
        for(int i=1;i<(int)ans.size();i++)
        {
            assert(ans[i].F>=1&&ans[i].F<=n);
            assert(ans[i].S>=1&&ans[i].S<=m);
            assert(ans[i].F!=ans[i-1].F);
            assert(ans[i].S!=ans[i-1].S);
            assert(ans[i].F+ans[i].S!=ans[i-1].F+ans[i-1].S);
            assert(ans[i].F-ans[i].S!=ans[i-1].F-ans[i-1].S);
        }*/
        printf("Case #%d: POSSIBLE\n",t);
        for(auto p:ans) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}

