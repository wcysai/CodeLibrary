#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 505
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
int H,W,h,w;
int ans[MAXN][MAXN];
void print()
{
    for(int i=1;i<=H;i++)
    {
        for(int j=1;j<=W;j++) printf("%d ",ans[i][j]);
        puts("");
    }
}
int main()
{
    scanf("%d%d%d%d",&H,&W,&h,&w);
    if(H%h==0&&W%w==0) {puts("No"); return 0;}
    else
    {
        puts("Yes");
        if(H%h!=0)
        {
            for(int i=1;i<=H;i++)
                for(int j=1;j<=W;j++)
                    ans[i][j]=(i%h==0?-501*(h-1)-1:501);
        }
        else
        {
            for(int i=1;i<=H;i++)
                for(int j=1;j<=W;j++)
                    ans[i][j]=(j%w==0?-501*(w-1)-1:501);
        }
        print();
    }
    return 0;
}

