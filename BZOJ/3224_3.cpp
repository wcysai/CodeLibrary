#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_mapped_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef ordered_set::iterator itr;
int n,opt,x;
ordered_set s;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&opt,&x);
        if(opt==1) s.insert(x);
        else if(opt==2) s.erase(x);
        else if(opt==3) printf("%d\n",s.order_of_key(x));
        else if(opt==4) printf("%d\n",*s.find_by_order(x-1));
        else if(opt==5)
        {
            itr it=s.lower_bound(x);it--;
            printf("%d\n",*it);
        }
        else if(opt==6)
        {
            itr it=s.upper_bound(x);
            printf("%d\n",*it);
        }
    }
    return 0;
}

