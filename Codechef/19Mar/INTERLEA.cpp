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
int n,ans,last;
string str[MAXN];
set<P> s[10];
vector<int> opt;
vector<int> cur;
vector<int> res;
void recover()
{
    cur.clear();res.clear();
    for(int i=0;i<10;i++) s[i].clear();
    for(int i=1;i<=n;i++) s[str[i][0]-'0'].insert(P(-100,i));
}
int compute()
{
    int ans=0;
    for(int i=1;i<(int)cur.size();i++)
    {
        ans+=(res[i]-res[i-1])*(res[i]-res[i-1]);
    }
    return ans;
}
void check(int x)
{
    if(x>ans)
    {
        ans=x;
        opt=cur;
    }
}
void process()
{
    int op=100,id=-1;
    for(int i=0;i<10;i++)
    {
        if(!s[i].size()) continue;
        if(abs(last-i)<op) 
        {
            op=abs(last-i);
            id=i;
        }
    }
    auto it=s[id].begin();
    cur.push_back(it->S);res.push_back(id);
    int now=100+(it->F);
    if(now!=99) s[str[it->S][now+1]-'0'].insert(P(it->F+1,it->S));
    s[id].erase(it);
    last=id;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        cin>>str[i];
        s[str[i][0]-'0'].insert(P(-100,i));
    }
    last=5;
    for(int j=0;j<100*n;j++) process();
    check(compute());
    recover();
    last=1;
    for(int j=0;j<100*n;j++) process();
    check(compute());
    for(int i=0;i<(int)opt.size();i++) printf("%d ",opt[i]);
    return 0;
}

