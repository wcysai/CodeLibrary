#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAXV 62
using namespace std;
int V,T;
pair<int,int> save[MAXV];
int match[110000];
bool used[110000];
bool dfs(int v)
{
    used[v]=true;
    for(int i=save[v].first;i<=save[v].second;i++)
    {
        int u=i,w=match[u];
        if(w<0||!used[w]&&dfs(w))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=V-1;v>=0;v--)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v))
            {
                res++;
            }
        }
    }
    return res;
}
int main()
{
    vector<int> ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&V);
        for(int i=0;i<V;i++)
        {
            scanf("%d %d",&save[i].first,&save[i].second);
            save[i].first+=V;
            save[i].second+=V;
        }
        printf("%d\n",bipartite_matching());
        ans.clear();
        for(int i=0;i<V;i++)
            if(match[i]>0)
              ans.push_back(i+1);
        for(int i=0;i<ans.size();i++)
            if(i==ans.size()-1) printf("%d\n",ans[i]); else printf("%d ",ans[i]);
    }
    return 0;
}

