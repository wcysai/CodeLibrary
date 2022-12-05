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
int n,k,a[MAXN];
vector<P> ans;
void construct(int n,int k)
{
    int g=__gcd(n,k);
    int a=n/g,b=k/g;
    int now=0;
    for(int i=0;i<(a-1)/2;i++)
    {
        for(int j=0;j<g;j++)
        {
            ans.push_back(P(now,(now+1)%n));
            now=(now+1)%n;
        }
        now=(now-g+n)%n;
        now=(now+2*k)%n;
    }
    int len=k-(g/2);
    for(int i=1;i<=(g-1)/2;i++)
        ans.push_back(P((now+i)%n,((now+i-len)%n+n)%n));
}
int main()
{
    scanf("%d%d",&n,&k);
    if(n%2==0) {puts("-1"); return 0;}
    construct(n,k);
    printf("%d\n",(int)ans.size());
    for(auto p:ans) printf("%d %d\n",p.F,p.S);
    return 0;
}

