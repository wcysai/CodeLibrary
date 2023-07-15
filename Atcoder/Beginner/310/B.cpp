#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,p[MAXN],c[MAXN];
set<int> s[MAXN];
bool check(int i,int j){
    if(p[i]<p[j]) return false;
    for(auto x:s[i]) if(!s[j].count(x)) return false;
    if(p[i]>p[j]) return true;
    for(auto x:s[j]) if(!s[i].count(x)) return true;
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i],&c[i]);
        for(int j=0;j<c[i];j++){
            int x; scanf("%d",&x);
            s[i].insert(x);
        }
    }
    bool f=false;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(check(i,j)) f=true;
    if(f) puts("Yes"); else puts("No");
    return 0;
}

