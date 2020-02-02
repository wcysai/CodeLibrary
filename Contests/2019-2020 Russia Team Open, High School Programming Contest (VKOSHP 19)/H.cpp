#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
int a,b;
vector<P> op;
ll res=0;
int main()
{
    scanf("%d%d",&a,&b);
    int need=b%9;
    int cur=a%9;
    res=need;
    ll p=10;
    int cnt=0;
    while(res%9!=cur||res<a)
    {
        res+=p;
        p*=10;
        cnt++;
    }
    if(res>a) op.push_back(P(0,(res-a)/9));
    if(cnt>0) op.push_back(P(1,cnt));
    if(b>need) op.push_back(P(0,(b-need)/9));
    puts("Stable");
    printf("%d\n",(int)op.size());
    for(auto p:op) if(!p.F) printf("+ %lld\n",p.S); else printf("- %lld\n",p.S);
}