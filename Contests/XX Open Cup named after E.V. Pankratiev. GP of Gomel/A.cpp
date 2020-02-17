#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
int n,k;
vector<vec> v;
bool flag=true;
void solve(vec &id)
{
    int sz=(int)id.size();
    assert(sz>=k);
    if(sz==k)
    {
        v.push_back(id);
        return;
    }
    int g=__gcd(sz/k,k);
    if(g==1) {flag=false; return;}
    vector<vec> tmp;
    vector<int> ttmp;
    int blocks=sz/g;
    int need=blocks/g;
    for(int i=0;i<sz;i++)
    {
        ttmp.push_back(id[i]);
        if(i%blocks==blocks-1) {tmp.push_back(ttmp); ttmp.clear();}
    }
    for(auto x:tmp) solve(x);
    for(int turns=0;turns<g;turns++)
    {
        vector<int> ttmp;
        for(auto &x:tmp)
        {
            for(int i=0;i<need;i++) ttmp.push_back(x.back()),x.pop_back();
        }
        solve(ttmp);
    }

}
int main()
{
    scanf("%d%d",&n,&k);
    vector<int> ttmp;
    for(int i=1;i<=n;i++) ttmp.push_back(i);
    solve(ttmp);
    if(!flag) puts("-1");
    else
    {
        printf("%d\n",(int)v.size());
        for(auto x:v)
        {
            for(auto y:x) printf("%d ",y);
            puts("");
        }
    }
    
    return 0;
}