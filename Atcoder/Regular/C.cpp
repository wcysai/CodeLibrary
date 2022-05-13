#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
set<P> s;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=max(n,m);i+=2)
        for(int j=min(n,i);j<=min(n,i+2);j++)
            for(int k=min(m,i);k<=min(m,i+2);k++)
                s.insert(P(j,k));
    printf("%d\n",(int)s.size());
    for(auto p:s) printf("%d %d\n",p.F,p.S);
    return 0;
}

