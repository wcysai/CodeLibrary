/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-06 20:55:54
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define prev __prev
#define next __next
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,k,a[MAXN],cur;
int prev[MAXN],next[MAXN],val[MAXN],id[MAXN];
bool valid[MAXN];
ll ans;
void del(int x)
{
    prev[next[x]]=prev[x];
    next[prev[x]]=next[x];
}
void inc()
{
    if(!valid[id[cur]]) del(cur);
    cur=next[cur];
    while(!valid[id[cur]]) {del(cur); cur=next[cur];} 
}
void dec()
{
    if(!valid[id[cur]]) del(cur);
    cur=prev[cur];
    while(!valid[id[cur]]) {del(cur); cur=prev[cur];} 
}
void solve(int now)
{
    for(int i=now;i<=n;i++) prev[i]=i-1,next[i]=i+1;
    vector<P> v;v.clear();
    int last=n-((now+n)&1);
    for(int i=now;i<=last;i++)
        v.push_back(P(a[i],i));
    sort(v.begin(),v.end());
    memset(valid,true,sizeof(valid));
    int cnt=0;
    for(int i=now;i<=last;i++) 
    {
        val[i]=v[cnt].F;id[i]=v[cnt].S;
        cnt++;
    }
    cur=(now+last)/2;
    for(int i=last;i>=now;i-=2)
    {
        //printf("%d %d %d %d\n",now,i,cur,val[cur]);
        ans+=1LL*val[cur]*i*now;
        if(i==now) break; 
        valid[i]=false;valid[i-1]=false;
        int x=a[i-1],y=a[i];
        if(x>y) swap(x,y);
        if(x>=val[cur]) dec();
        else if(y<=val[cur]) inc();
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) solve(i);
    printf("%lld\n",ans);
    return 0;
}

