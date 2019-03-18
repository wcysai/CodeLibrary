#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int N,L,T;
int X[MAXN];
int W[MAXN],d[MAXN],ans[MAXN];
map<int,int> mp;
vector<int> dest;
int main()
{
    scanf("%d%d%d",&N,&L,&T);
    for(int i=1;i<=N;i++) 
    {
        scanf("%d%d",&X[i],&W[i]);
        if(W[i]==1)
        {
            d[i]=(X[i]+T)%L;
            dest.push_back(d[i]);
        }
        else
        {
            d[i]=((X[i]-T)%L+L)%L;
            dest.push_back(d[i]);
        }
    }  
    sort(dest.begin(),dest.end());
    int lab=1;
    if(W[1]==1)
    {
        int cnt=0;
        for(int i=2;i<=N;i++)
        {
            if(W[i]==2)
            {
                int dist=X[i]-X[1];
                if(dist<0) dist+=L;
                if(2*T>=dist) cnt+=(2*T-dist-1)/L+1;
            }
        }
        lab=1+cnt%N;
    }
    else
    {
        int cnt=0;
        for(int i=2;i<=N;i++)
        {
            if(W[i]==1)
            {
                int dist=X[1]-X[i];
                if(dist<0) dist+=L;
                if(2*T>=dist) cnt+=(2*T-dist)/L+1;
            }
        }
        lab=((1-cnt%N)+N)%N;
        if(lab==0) lab=N;
    }
    int p=lower_bound(dest.begin(),dest.end(),d[1])-dest.begin();
    for(int i=1;i<=N;i++)
    {
        ans[lab]=dest[p];
        lab++; if(lab>N) lab-=N;
        p++; if(p>=N) p-=N;
    }
    for(int i=1;i<=N;i++) printf("%d\n",ans[i]);
    return 0;
}

