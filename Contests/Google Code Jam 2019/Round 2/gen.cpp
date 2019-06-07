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
mt19937 wcy(time(NULL));
int main()
{
    printf("%d\n",1000);
    for(int i=0;i<1000;i++)
    {
        printf("%d\n",10);
        int lastx=-1,lasty=-1;
        for(int i=1;i<=10;i++)
        {
roll:       int x=wcy()%(30*i)+1,y=wcy()%(30*i)+1;
            if(x<=lastx&&y<=lasty) goto roll;
            lastx=x; lasty=y;
            printf("%d %d\n",x,y);
        }
    }
    return 0;
}

