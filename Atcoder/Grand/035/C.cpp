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
int main()
{
    scanf("%d",&n);
    if(__builtin_popcount(n)==1)
    {
        puts("No");
        return 0;
    }
    puts("Yes");
    for(int i=1;i<=2;i++) 
    {
        printf("%d %d\n",i,i+1);
        printf("%d %d\n",n+i,n+i+1);
    }
    printf("%d %d\n",3,n+1);
    if(n&1)
    {
        for(int i=4;i<=n;i+=2) 
        {
            printf("%d %d\n",i,i+1);
            printf("%d %d\n",n+i,n+i+1);
            printf("%d %d\n",i+1,1);
            printf("%d %d\n",n+i,1);
        }
    }
    else
    {
        int now=1;
        while(now*2<=n) now*=2;
        now++;
        for(int i=4;i<=now;i+=2) 
        {
            printf("%d %d\n",i,i+1);
            printf("%d %d\n",n+i,n+i+1);
            printf("%d %d\n",i+1,1);
            printf("%d %d\n",n+i,1);
        }
        now++;
        printf("%d %d\n",now,now-1);
        printf("%d %d\n",n+now,2);
        for(int i=now+2;i<=n;i+=2)
        {
            int x=i^(i-1);
            printf("%d %d\n",i-1,i);
            printf("%d %d\n",n+i,n+i-1);
            printf("%d %d\n",i-1,x);
            printf("%d %d\n",n+i,x);
        }
    }
    return 0;
}

