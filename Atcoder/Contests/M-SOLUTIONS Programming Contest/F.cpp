#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 2005
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
typedef bitset<2000> bs;
int n;
bs win[MAXN];
int a[MAXN][MAXN];
bs pre[MAXN],tmp;
string str;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        cin>>str;
        for(int j=0;j<i;j++)
        {
            int x=str[j]-'0';
            if(x) win[i].set(j); else win[j].set(i);
        }
    }
    pre[0].set(0);
    for(int i=1;i<n;i++)
    {
        bs suf; suf.reset(); suf.set(i);
        if((win[i]&pre[i-1]).count()) pre[i].set(i);
        for(int j=i-1;j>=0;j--)
        {
            if((win[j]&suf).count())
            {
                suf.set(j);
                if(pre[j].test(j)) pre[i].set(j);
            }
        }
    }
    printf("%d\n",(int)pre[n-1].count());
    return 0;
}

