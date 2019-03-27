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
int n,k;
string str;
deque<int> deq;
void convert()
{
    for(int i=0;i<n;i++) if(str[i]=='A') deq.push_back(0); else deq.push_back(1);
}
void go()
{
    if(!deq[0]) {deq[0]=1; k--; return;}
    deq.pop_front();
    for(int i=0;i<(int)deq.size();i++) deq[i]^=1;
    deq.push_back(0); k--;
}
void go2()
{
    int cnt=0;
    if(deq[0]==1&&deq[1]==0) cnt=2;
    if(deq[0]==0&&deq[1]==0) cnt=3;
    if(deq[0]==0&&deq[1]==1) cnt=4;
    if(deq[0]==1&&deq[1]==1) cnt=3;
    deq.pop_front(); deq.pop_front();
    deq.push_back(1); deq.push_back(0); k-=cnt;
}
void print()
{
    for(int i=0;i<n;i++) printf("%c",deq[i]?'B':'A');
}
int main()
{
    scanf("%d%d",&n,&k);
    cin>>str;
    if(n==1)
    {
        if(k&1) str[0]=(str[0]='A'?'B':'A'); 
        cout<<str<<endl; return 0;
    }
    convert(); 
    for(int i=1;i<=n;i++)
    {
        if(k<=4)
        {
            while(k) go();
            break;
        }
        else go2();
    }
    k%=4; while(k) go();
    print();
    return 0;
}

