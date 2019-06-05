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
int l,tot;
string str;
int st[MAXN];
ll cur;
bool flag=true;
int main()
{
    scanf("%d ",&l);
    for(int i=0;i<l;i++)
    {
        getline(cin,str);
        if(str[0]=='f')
        {
            int x=atoi(str.substr(4).c_str());
            st[tot++]=x;
        }
        else if(str[0]=='a')
        {
            ll tmp=1;
            for(int i=0;i<tot;i++) 
            {
                tmp=tmp*st[i];
                if(tmp>((1LL<<32)-1)) flag=false;
            }
            if(flag) cur+=tmp;
            if(cur>((1LL<<32)-1)) flag=false;
        }
        else 
        {
            tot--;
        }
    }
    if(!flag) puts("OVERFLOW!!!"); else printf("%lld\n",cur);
    return 0;
}

