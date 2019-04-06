#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<string> solve(int n)
{
    if(n==1) return vector<string>{"0","1"};
    if(n==2) return vector<string>{"00","01","10","11"};
    vector<string> v=solve(n-2);
    vector<string> ret; ret.clear();
    for(int i=0;i<(int)v.size();i++) ret.push_back((i&1?"00":"01")+v[i]);
    for(int i=0;i<(int)v.size();i++) ret.push_back((i&1?"01":"10")+v[i]);
    for(int i=0;i<(int)v.size();i++) ret.push_back((i&1?"10":"11")+v[i]);
    for(int i=0;i<(int)v.size();i++) ret.push_back((i&1?"11":"00")+v[i]);
    return ret;
}
int main()
{
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
    int n; scanf("%d",&n);
    vector<string> ans=solve(n);
    for(int i=0;i<(int)ans.size();i++) cout<<ans[i]<<endl;
    return 0;
}
