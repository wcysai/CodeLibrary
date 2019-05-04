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
int h,w,n;
int x,y,dx,dy;
string s,t;
int main()
{
    scanf("%d%d%d",&h,&w,&n);
    scanf("%d%d",&x,&y);
    dx=x; dy=y;
    cin>>s; cin>>t;
    bool f=true;
    x=dx; y=dy;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='U') x--;
        if(x<1) f=false;
        if(t[i]=='D') x++;
        if(x>h) x=h;
    }
    x=dx; y=dy;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='D') x++;
        if(x>h) f=false;
        if(t[i]=='U') x--;
        if(x<1) x=1;
    }
    x=dx; y=dy;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='L') y--;
        if(y<1) f=false;
        if(t[i]=='R') y++;
        if(y>w) y=w;
    }
    x=dx; y=dy;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R') y++;
        if(y>w) f=false;
        if(t[i]=='L') y--;
        if(y<1) y=1;
    }
    if(f) puts("YES"); else puts("NO");
    return 0;
}

