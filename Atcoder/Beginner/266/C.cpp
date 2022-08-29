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
int n,k,x[4],y[4];
int main()
{
    for(int i=0;i<4;i++) scanf("%d%d",&x[i],&y[i]);
    bool f=true;
    for(int i=0;i<4;i++)
    {
        int j=(i+1)%4,k=(i+2)%4;
        if(1LL*(y[k]-y[j])*(x[j]-x[i])-1LL*(x[k]-x[j])*(y[j]-y[i])<=0) f=false;
    }
    if(f) puts("Yes"); else puts("No");
    return 0;
}

