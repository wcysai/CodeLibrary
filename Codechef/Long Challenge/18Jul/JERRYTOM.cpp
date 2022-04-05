/*************************************************************************
    > File Name: JERRYTOM.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-12 01:28:48
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
const int N=100006;
vector <int> arc[N];
int t,n, m, R[N], SA[N], label[N];
priority_queue <pair<int, int> > heap;
void Construct() 
{
    fill(R+1, R+1+n, -1);
    fill(label+1, label+1+n, 0);
    while(heap.size()) heap.pop();
    for(int i=1; i<=n; i++) heap.push(make_pair(0, i));
    for(int cnt=n; cnt>=1; ) {
        int id=heap.top().second;
        heap.pop();
        if(R[id]!=-1) continue;
        SA[cnt]=id, R[id]=cnt--;
        for(int i=0, len=(int)arc[id].size(); i<len; i++) {
            int u=arc[id][i];
            if(R[u]!=-1) continue;
            label[u]++;
            heap.push(make_pair(label[u], u));
        }
    }
}

void Color(int u) {
    for(int i=0, len=(int)arc[u].size(); i<len; i++) {
        int v=arc[u][i];
        if(label[v]==-1) continue;
        R[label[v]]=u;
    }
    for(int i=1; label[u]==-1; i++) if(R[i]!=u) label[u]=i;
}

int Color_Graph() {
    fill(label+1, label+1+n, -1);
    fill(R+1, R+1+n, -1);
    for(int i=n; i>0; i--) Color(SA[i]);
    int ans=0;
    for(int i=1; i<=n; i++) ans=max(ans, label[i]);
    return ans;
}

int main() 
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i=1; i<=n; i++) arc[i].clear();
        for(int i=0, a, b; i<m; i++) {
            scanf("%d%d", &a, &b);
            arc[a].push_back(b);
            arc[b].push_back(a);
        }
        Construct();
        printf("%d\n", Color_Graph());
    }
    return 0;
}
