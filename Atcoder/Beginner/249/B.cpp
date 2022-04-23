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
string str;
set<char> s;
int main()
{
    cin>>str;
    bool f1=false,f2=false,f=true;
    for(int i=0;i<(int)str.size();i++) 
    {
        if(s.count(str[i])) f=false;
        if(str[i]>='A'&&str[i]<='Z') f2=true;
        if(str[i]>='a'&&str[i]<='z') f1=true;
        s.insert(str[i]);
    }
    if(f1&&f2&&f) puts("Yes"); else puts("No");
    return 0;
}

