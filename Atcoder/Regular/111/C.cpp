#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN],p[MAXN];
vector<P> ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    for(int i=1;i<=n;i++) if(p[i]!=i&&a[i]<=b[p[i]]) {puts("-1"); return 0;}
    set<P> s;
    for(int i=1;i<=n;i++) if(p[i]!=i) s.insert(P(b[p[i]],i));
    while(s.size())
    {
        auto it=prev(s.end());
        int id=it->S,nxt=p[id];
        s.erase(s.find(P(b[p[id]],id)));
        s.erase(s.find(P(b[p[nxt]],nxt)));
        ans.push_back(P(id,p[id]));
        swap(p[id],p[nxt]);
        if(p[id]!=id) s.insert(P(b[p[id]],id));
    }
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
    return 0;
}