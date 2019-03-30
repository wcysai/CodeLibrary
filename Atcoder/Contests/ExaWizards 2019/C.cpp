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
int n,q;
char str[MAXN];
char x[MAXN][2],y[MAXN][2];
int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",str+1);
    int l=0,r=n+1;
    for(int i=0;i<q;i++)
    {
        scanf("%s",x[i]);
        scanf("%s",y[i]);
    }
    for(int i=q-1;i>=0;i--)
    {
        if(y[i][0]=='L')
        {
            if(r<=n&&x[i][0]==str[r]) r++;
            if(l<n&&x[i][0]==str[l+1]) l++;
        }
        else 
        {
            if(l>=1&&x[i][0]==str[l]) l--;
            if(r>1&&x[i][0]==str[r-1]) r--;
        }
    }
    int ans=min(n,l+n+1-r);
    printf("%d\n",n-ans);
    return 0;
}

