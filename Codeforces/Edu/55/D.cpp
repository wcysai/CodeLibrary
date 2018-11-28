/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-28 23:10:03
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
int n,k,a[MAXN];
vector<int> leaf;
deque<int> nonleaf;
vector<P> edge;
void add_edge(int u,int v)
{
    edge.push_back(P(u,v));
    a[u]--;a[v]--;
}
int main()
{
    int sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]); sum+=a[i];
        if(a[i]==1) leaf.push_back(i); else nonleaf.push_back(i);
    }
    if(sum<2*(n-1))
    {
        puts("NO");
        return 0;
    }
    int diam=(int)nonleaf.size()-1;
    diam+=min(2,(int)leaf.size());
    printf("YES %d\n",diam);
    for(int i=1;i<(int)nonleaf.size();i++) add_edge(nonleaf[i-1],nonleaf[i]);
    if(leaf.size()>=1) add_edge(leaf[0],nonleaf.front());
    if(leaf.size()>=2) add_edge(leaf[1],nonleaf.back());
    int now=0;
    for(int i=2;i<(int)leaf.size();i++)
    {
        while(now<(int)nonleaf.size()&&a[nonleaf[now]]==0) now++;
        add_edge(leaf[i],nonleaf[now]);
    }
    printf("%d\n",(int)edge.size());
    for(auto e:edge) printf("%d %d\n",e.F,e.S);
    return 0;
}

