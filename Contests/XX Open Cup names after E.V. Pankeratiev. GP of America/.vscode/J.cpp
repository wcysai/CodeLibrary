#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=1;i<=n;++i)
using namespace std;

struct state
{
    vector<int> q1,q2;
    int t;
    friend bool operator <(state x,state y)
    {
        if (x.t!=y.t)return x.t<y.t;
        auto t1=mp(x.q1.size(),x.q2.size());
        auto t2=mp(y.q1.size(),y.q2.size());
        if (t1!=t2)return t1<t2;
        for(int i=0;i<t1.first;i++)
            if (x.q1[i]!=y.q1[i])return x.q1[i]<y.q1[i];
        for(int i=0;i<t1.second;i++)
            if (x.q2[i]!=y.q2[i])return x.q2[i]<y.q2[i];
        return 0;
    }
};
set<state> DIC;

vector<vector<int> > now,dic;
vector<int> done;
int n,m;

bool exist(vector<int> q1,vector<int> q2,int left)
{
    state x; x.q1.clear(); x.q2.clear(); x.t=left;
    for(auto p:q1)x.q1.pb(p);
    for(auto p:q2)x.q2.pb(p);
    //sort(x.q1.begin(),x.q1.end());
    sort(x.q2.begin(),x.q2.end());

    int cnt=0;
    for(auto p:q1)if (p==1)cnt++;
    for(auto p:q2)if (p==1)cnt++;
    if (cnt==n){ cout<<n<<endl; exit(0); }

    if (DIC.find(x)!=DIC.end())return 1;
    DIC.insert(x);
    return 0;
}
void dfs(vector<int> todo,vector<int> done,int left)
{
    int sum=0; for(auto p:todo)sum+=p; 
    if (sum<left)return;
    left=min(left,sum-left);
    if (exist(todo,done,left))return;
    if (todo.empty())
    {
        if (left==0)
        {
            sort(done.begin(),done.end());
            dic.pb(done);
        }
        return;
    }
    
    int t=todo.back(); todo.pop_back();
    //vector<int> pre; pre.clear(); for(auto p:done)pre.pb(p);
    for(int i=0;i<=min(left,t);i++)
    {
        if (i)done.pb(i); if (t-i)done.pb(t-i);
        dfs(todo,done,left-i);
        if (i)done.pop_back(); if (t-i)done.pop_back();
       // done.clear(); for(auto p:pre)done.pb(p);
    }
}
int main()
{
    cin>>n>>m;

    now.clear(); vector<int> t; t.clear(); t.pb(n);
    now.pb(t);
    for(int i=1;i<=m;i++)
    {
        int x; scanf("%d",&x); x=min(x,n-x);
        dic.clear(); DIC.clear();
        for(auto p:now)
        {
            done.clear();
            dfs(p,done,x);
        }
        now.clear();
        for(auto p:dic)now.pb(p);

        cout<<now.size()<<endl;
        /*if (i==4)
        {
            puts(""); puts(""); cout<<"after "<<i<<endl; 
            for(auto q:now)
            {
             putchar('(');
             for(auto p:q)cout<<p<<" "; 
             puts(")");
            }   
        }*/
        
    }
    int ans=0;
    for(auto q:now)
    {
        int cnt=0;
        for(auto p:q)if (p==1)cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}