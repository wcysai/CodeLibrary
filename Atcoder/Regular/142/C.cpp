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
int n,k,a[MAXN];
int ask(int u,int v)
{
    printf("? %d %d\n",u,v);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    assert(x!=-1);
    return x;
}
void answer(int d)
{
    printf("! %d\n",d);
    fflush(stdout);
    exit(0);
}
int main()
{
    scanf("%d",&n);
    vector<P> v;
    for(int i=3;i<=n;i++)
    {
        int sum=ask(1,i)+ask(2,i);
        v.push_back(P(sum,i));
    }
    sort(v.begin(),v.end());
    if(n==3)
    {
        if(v[0].F==3) answer(1); else {assert(v[0].F==2); answer(2);}
        return 0;
    }
    if(v[0].F==3) 
    {
        if(v[0].F==v[1].F) 
        {
            if(ask(v[0].S,v[1].S)==1) answer(3); else answer(1);
        }
        else answer(1);
    }
    else { answer(v[0].F);}
    return 0;
}

