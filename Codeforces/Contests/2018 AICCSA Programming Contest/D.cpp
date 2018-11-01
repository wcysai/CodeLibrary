/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-01 17:19:00
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
int T,n,k;
unordered_multiset<int> ms;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);ms.clear();
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x); ms.insert(x);
        }
        int now=-1;
        bool f=true;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if(!f) continue;
            if(!ms.count(x))
            {
                if(now!=-1) {f=false; continue;}
                now=x;
            }
            else ms.erase(ms.find(x));
        }
        if(!f) {puts("NO"); continue;}
        if(!ms.size()) {puts("YES"); continue;}
        if(abs(now-*(ms.begin()))<=k) puts("YES"); else puts("NO");
    }
    return 0;
}

