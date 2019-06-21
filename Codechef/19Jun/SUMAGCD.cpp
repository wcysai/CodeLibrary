#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
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
int T,n,pre[MAXN],suf[MAXN];
vector<int> v;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        v.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int x;scanf("%d",&x);
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        int sz=(int)v.size();
        if(sz==1) {printf("%d\n",2*v[0]); continue;}
        pre[0]=0;
        for(int i=1;i<=sz;i++) pre[i]=__gcd(pre[i-1],v[i-1]);
        suf[sz+1]=0;
        for(int i=sz;i>=1;i--) suf[i]=__gcd(suf[i+1],v[i-1]);
        int ans=0;
        for(int i=1;i<=sz;i++) ans=max(ans,v[i-1]+__gcd(pre[i-1],suf[i+1]));
        printf("%d\n",ans);
    }
    return 0;
}

