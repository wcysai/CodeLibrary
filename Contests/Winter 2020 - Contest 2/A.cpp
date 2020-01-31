#include<bits/stdc++.h>
#define MAXN 1005
#define INF 900000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
int T,n;
P p[MAXN];
vector<int> v;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i].F,&p[i].S);
        sort(p+1,p+n+1);
        if(p[n/2].F!=p[n/2+1].F)  printf("%d %d %d %d\n",p[n/2].F,-INF,p[n/2+1].F,INF);
        else printf("%d %d %d %d\n",p[n/2].F-1,INF,p[n/2].F+1,2*p[n/2].S+1-INF);
    }
    return 0;
} 