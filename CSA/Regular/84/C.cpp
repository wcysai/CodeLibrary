/*************************************************************************
    > File Name: 84C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-18 23:01:04
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
int n;
set<int> s;
vector<P> op;
int main()
{
    scanf("%d",&n);
    int sum=0,x;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        sum+=(x&1);
        if(s.count(x)) s.erase(x); else s.insert(x);
    }
    if(sum&1) {puts("-1");return 0;}
    while(s.size())
    {
        auto it=s.begin();
        auto it2=s.end();it2--;
        int x=*it,y=*it2;
        if(s.size()==1)
        {
            op.push_back(P(x,x/2));
            break;
        }
        s.erase(x);s.erase(y);
        int z=y-x;
        if(s.count(z)) s.erase(z); else s.insert(z);
        op.push_back(P(y,x));
    }
    printf("%d\n",(int)op.size());
    for(int i=0;i<(int)op.size();i++)
        printf("%d %d\n",op[i].F,op[i].S);
    return 0;
}

