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
int n,m,a[MAXN],b[MAXN];
vector<int> upd[MAXN];
int ans[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    int dead=m;
    for(int i=1;i<=n;i++) {scanf("%d%d",&a[i],&b[i]); upd[a[i]+1].push_back(i); dead=min(dead,b[i]);}
    multiset<int> s;
    for(int i=1;i<=n;i++) s.insert(a[i]);
    for(int i=1;i<=dead;i++)
    {
        for(auto x:upd[i]) {s.erase(s.find(a[x])); s.insert(b[x]);}
        int r=m,l=*(--s.end());
        ans[l-i+1]+=1; ans[r-i+2]-=1;
    }
    for(int i=1;i<=m;i++) ans[i]+=ans[i-1];
    for(int i=1;i<=m;i++) printf("%d%c",ans[i],i==m?'\n':' ');
    return 0;
}

