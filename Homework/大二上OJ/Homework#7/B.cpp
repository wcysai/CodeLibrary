#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#define MAXN 505
using namespace std;
int perm[MAXN],num[MAXN];
bool used[MAXN];
int n,k;
int dfs(int x,int cnt)
{
    if(used[x]) return cnt;
    used[x]=true;
    num[x]=dfs(perm[x],cnt+1);
    return num[x];
}
int main()
{
    scanf("%d",&n);
    while(n>0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&perm[i]);
            perm[i]--;
        }
        memset(used,false,sizeof(used));
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
            if(!used[i]) dfs(i,0);
        scanf("%d",&k);
        while(k>0)
        {
            char str[MAXN],str2[MAXN];
            gets(str);
            int x=strlen(str);
            for(int i=0;i<x;i++)
                str[i]=str[i+1];
            x--;
            for(int i=x;i<n;i++)
                str[i]=' ';
            for(int i=0;i<n;i++)
                str2[i]=' ';
            for(int i=0;i<n;i++)
            {
                int times=k%num[i];
                int t=i;
                for(int j=0;j<times;j++)
                    t=perm[t];
                str2[t]=str[i];
            }
            str2[n]='\0';
            printf("%s\n",str2);
            scanf("%d",&k);
        }
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}
