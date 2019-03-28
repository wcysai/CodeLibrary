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
int N,M,Y,X[MAXN],ans[MAXN];
vector<int> v;
vector<P> p;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d",&N,&M,&Y);
    for(int i=1;i<=N;i++) scanf("%d",&X[i]);
    ll sum=0;
    for(int i=1;i<=N;i++)
    {
        ans[i]=X[i]*M/Y;
        p.push_back(P(X[i]*M-ans[i]*Y,i));
        sum+=ans[i];
    }
    sort(p.begin(),p.end(),greater<P>());
    for(int i=0;i<M-sum;i++) ans[p[i].S]++;
    for(int i=1;i<=N;i++) printf("%d ",ans[i]);
    return 0;
}

