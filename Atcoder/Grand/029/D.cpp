/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-16 19:27:12
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int h,w,k;
set<int> v[MAXN];
int main()
{
    scanf("%d%d",&h,&w);
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[y].insert(x);
    }
    if(k==0)
    {
        printf("%d\n",h);
        return 0;
    }
    int ans=h;
    int now=1;
    for(int i=1;i<=w;i++)
    {
        auto it=v[i].lower_bound(now);
        if(it!=v[i].end()) ans=min(ans,*it-1);
        if(i==w) break;
        if(v[i].count(now+1)||now==h) break;
        now++;
        bool f=true;
        while(now<=h&&v[i+1].count(now))
        {
            now++;
            if(v[i].count(now)) {f=false; break;}
        }
        if(now>h||!f) break;
    }
    printf("%d\n",ans);
    return 0;
}

