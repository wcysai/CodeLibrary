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
int grundy[MAXN];
bool has[MAXN];
int main()
{
    scanf("%d",&k);
    grundy[0]=0;
    for(int i=1;i<=100;i++)
    {
        memset(has,false,sizeof(has));
        for(int j=1;j<=i;j++)
        {
            int l=max(0,j-k);
            int r=max(0,i+1-j-k);
            has[grundy[l]^grundy[r]]=true;
        }
        for(int j=0;;j++)
        {
            if(!has[j]) {grundy[i]=j; break;}
        }
        printf("%d %d\n",i,grundy[i]);
    }
    return 0;
}

