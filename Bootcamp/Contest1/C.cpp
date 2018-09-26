/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 20:03:52
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
int N,M,tot,x;
vector<int> v[MAXN];
map<string,int> mp;
string str;
int main()
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        cin>>str;scanf("%d",&x);
        if(mp.find(str)==mp.end()) mp[str]=tot++;
        v[mp[str]].push_back(x);
    }
    for(int i=0;i<tot;i++) sort(v[i].begin(),v[i].end());
    scanf("%d",&M);
    int cur=0;
    bool f=true;
    for(int i=0;i<M;i++)
    {
        cin>>str;
        if(mp.find(str)==mp.end()) {f=false;}
        else
        {
            int now=mp[str];
            auto it=upper_bound(v[now].begin(),v[now].end(),cur);
            if(it==v[now].end()) f=false; else cur=*it;
        }
    }
    if(f) puts("Yes"); else puts("No");
    return 0;
}

