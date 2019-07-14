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
int n,k,a[MAXN];
map<int,int> mp;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) 
    {
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }
    if(n%3!=0)
    {
        if(mp.size()==1&&a[0]==0) puts("Yes");
        else puts("No");
    }
    else
    {
        bool f=true;
        if(mp.size()>3) f=false;
        int x=0;
        for(auto p:mp)
        {
            if(p.S%(n/3)!=0) f=false;
            for(int j=0;j<p.S/(n/3);j++) x^=p.F;
        }
        if(x!=0) f=false;
        if(f) puts("Yes"); else puts("No");
    }
    return 0;
}

