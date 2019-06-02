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
bs win[MAXN],twin[MAXN];
int a[MAXN][MAXN];
bs dpl[MAXN],dpr[MAXN],tdpl[MAXN],tdpr[MAXN];
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
            if(x) 
            {
                win[i].set(j);
                twin[j].set(i);
            }
            else 
            {
                win[j].set(i);
                twin[i].set(j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        dpl[i].set(i); dpr[i].set(i);
        tdpl[i].set(i); tdpr[i].set(i);
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=0;i+len-1<n;i++)
        {
            int j=i+len-1;
            if((dpr[i+1]&tdpl[j]&win[i]).count())
            {
                dpl[i].set(j);
                tdpl[j].set(i);
            }
            if((dpr[i]&tdpl[j-1]&win[j]).count())
            {
                dpr[i].set(j);
                tdpr[j].set(i);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) if(dpl[i].test(n-1)&&dpr[0].test(i)) ans++;
    printf("%d\n",ans);
    return 0;
}

