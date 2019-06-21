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
int n,cnt,ans;
bool has[MAXN];
int b[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        int x;
        scanf("%d",&x);
        if(x>0) {has[x]=true; cnt++;}
    }
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&b[i]);
    }
    if(cnt==0) {puts("0"); return 0;}
    if(n==1) {puts("1"); return 0;}
    int last=-1,pos=-1;;
    for(int i=n;i>=1;i--)
    {
        if(b[i])
        {
            last=b[i];
            pos=i;
            break;
        }
    }
    bool f=true;
    for(int i=last-1;i>=1;i--)
    {
        pos--;
        if(pos<=0) f=false;
        if(b[pos]!=b[pos+1]-1) f=false;
    }
    if(f) {printf("%d\n",pos-1+))}
    while(true)
    {
        ans++;
        int x=b.back();
        if(has[x+1]) {b.push_back(x+1); has[x+1]=false; cnt--;}
        else b.push_back(0);
        if(b.front()) {has[b.front()]=true; cnt++;}
        b.pop_front();
        if(!cnt) {printf("%d\n",ans); return 0;}
    }
    return 0;
}

