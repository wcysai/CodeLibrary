#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 200005
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
int n,a,b,c,d;
char str[MAXN+1];
bool go(int x,int y)
{
    for(int i=x;i<=y;i++)
    {
        if(str[i]=='#'&&str[i+1]=='#') return false;
    }
    return true;
}
int main()
{
    scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
    scanf("%s",str+1);
    if(!go(a,c)||!go(b,d)) {puts("No"); return 0;}
    if(c<d) puts("Yes");
    else
    {
        bool f=false;
        for(int i=b;i<=d;i++)
        {
            if(str[i]!='#'&&str[i-1]!='#'&&str[i+1]!='#') f=true;
        }
        if(f) puts("Yes"); else puts("No");
    }
    return 0;
}

