/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-30 17:26:52
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
struct segtree
{
    int cnt[4*MAXN];
    void update(int k,int l,int r,int p,int v)
    {
        if(l==r) {cnt[k]+=v; return;}
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,v); else update(k*2+1,mid+1,r,p,v);
        cnt[k]=cnt[k*2]+cnt[k*2+1];
    }
    int find(int k,int l,int r,int x)
    {
        if(l==r) return l;
        int mid=(l+r)/2;
        if(cnt[k*2+1]>=x) return find(k*2+1,mid+1,r,x);
        else return find(k*2,l,mid,x-cnt[k*2+1]);
    }
}seg;
vector<int> v;
P query[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&query[i].F,&query[i].S);
        v.push_back(query[i].S);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    int sz=(int)v.size();
    for(int i=0;i<n;i++)
    {
        if(query[i].F==0) printf("%d\n",v[seg.find(1,1,sz,query[i].S)-1]);
        else
        {
            query[i].S=lower_bound(v.begin(),v.end(),query[i].S)-v.begin()+1;
            seg.update(1,1,sz,query[i].S,query[i].F);
        }
    }
    return 0;
}

