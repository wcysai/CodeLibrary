/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-06 13:40:35
 ************************************************************************/

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
int T,n,m;
unsigned X,Y,Z;
unsigned RNG61()
{
    X=X^(X<<11);
    X=X^(X>>4);
    X=X^(X<<5);
    X=X^(X>>14);
    unsigned W=(X^Y^Z);
    X=Y;
    Y=Z;
    Z=W;
    return Z;
}
struct node{unsigned a,b,c;};
set<node> s;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%u%u%u",&n,&m,&X,&Y,&Z);
        s.clear();
        for(int i=1;i<=100000;i++) 
        {
            unsigned x=RNG61();
            printf("%u\n",x);
            if(s.count((node){X,Y,Z})) {printf("%d\n",i); break;}
            s.insert((node){X,Y,Z});
        }
    }
    return 0;
}

