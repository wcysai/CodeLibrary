/*************************************************************************
    > File Name: 85D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-01 23:26:24
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int cnt[32];
int main()
{
    scanf("%d%d",&n,&k);
    int now=1<<30;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        now-=(1<<a[i]);
    }
    multiset<int> s;
    for(int i=0;i<30;i++)
        if((now>>i)&1) s.insert(i);
    int sz=(int)s.size();
    assert(sz<=k);
    for(int i=0;i<k-sz;i++)
    {
        auto p=s.end();
        p--;
        int num=*p;
        s.erase(p);
        s.insert(num-1);s.insert(num-1);
    }
    for(auto it:s) cnt[it]++;
    return 0;
}

