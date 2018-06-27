#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<deque>
#define MAXN 1005
using namespace std;
int ans,n;
int now[40];
bool dfs(int depth)
{
    if(depth>ans) return false;
    if(now[depth]<<(ans-depth)<n) return false;
    if(now[depth]==n) return true;
    for(int i=0;i<=depth;i++)
    {
        now[depth+1]=now[depth]+now[i]; if(dfs(depth+1)) return true;
        now[depth+1]=now[depth]-now[i]; if(now[depth+1]>0&&dfs(depth+1)) return true;
    }
    return false;
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        if(!n) break;
        now[0]=1;
        for(ans=0;!dfs(0);ans++);
        printf("%d\n",ans);
    }
}
