#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#define MAXN 100000
using namespace std;
int m;
char str[MAXN];
vector<int> G[26];
int num[MAXN];
bool flag[MAXN];
int main()
{
    scanf("%d",&m);
    scanf("%s",str);
    for(int i=0;i<26;i++)
        G[i].clear();
    memset(num,0,sizeof(num));
    memset(flag,0,sizeof(flag));
    int cnt=strlen(str);
    printf("%d\n",cnt);
    for(int i=0;i<strlen(str);i++)
        G[(int)str[i]-97].push_back(i);
    int k=0;
    while(true)
    {
        for(int i=0;i<G[k].size();i++)
        {
            flag[G[k][i]]=true;
            for(int j=max(0,G[k][i]-m+1);j<min((int)strlen(str),G[k][i]+m);j++)
            {
                if(num[j]==0) cnt--;
                num[j]++;
            }
        }
        if(cnt==0)
        {
             for(int i=0;i<G[k].size();i++)
          {
             int f=1;
            for(int j=max(0,G[k][i]-m+1);j<min((int)strlen(str),G[k][i]+m);j++)
                if(num[j]==1) f=0;
            if(f)
            {
                flag[G[k][i]]=false;
                for(int j=max(0,G[k][i]-m+1);j<min((int)strlen(str),G[k][i]+m);j++)
                    num[j]--;
            }
          }
          break;
        }
        else k++;
    }
    for(int k=0;k<26;k++)
    {
        int f=1;
        for(int i=0;i<G[k].size();i++)
        {
            if(flag[G[k][i]]) printf("%c",str[G[k][i]]); else f=0;
        }
        if(!f) break;
    }
    printf("\n");
    for(int i=0;i<strlen(str);i++) printf("%d ",num[i]);
    return 0;
}
