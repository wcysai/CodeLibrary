#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,tot,p[MAXN];
vector<int> save[MAXN];
int ans[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) ans[i]=-1;
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    set<P> s;
    for(int i=1;i<=n;i++)
    {
        int x=p[i];
        if(!s.size()||((*(--s.end())).F<x))
        {
            if(k==1) {ans[x]=i; continue;}
            tot++;
            s.insert(P(x,tot));
            save[tot].push_back(x);
        }
        else
        {
            auto p=*lower_bound(s.begin(),s.end(),P(x,0));
            save[p.S].push_back(x);
            s.erase(s.find(p));
            if(save[p.S].size()>=k)
            {
                for(auto x:save[p.S]) ans[x]=i;
                save[p.S].clear();
            }
            else
            {
                p.F=x;
                s.insert(p);
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
    return 0;
}

