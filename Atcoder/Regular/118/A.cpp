#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
set<int> s;
set<int> ns;
int main()
{
    scanf("%d%d",&t,&n);
    for(int i=1;i<=100;i++) s.insert((100+t)*i/100);
    for(int i=1;i<=100+t;i++) if(!s.count(i)) ns.insert(i);
    ll ans=1LL*(100+t)*(n/(int)ns.size());
    n=n%(int)ns.size();
    if(n==0) {n=(int)ns.size(); ans-=100+t;}
    int cnt=0;
    for(auto x:ns)
    {
        cnt++;
        if(n==cnt) {printf("%lld\n",ans+x); return 0;}
    }
    return 0;
}