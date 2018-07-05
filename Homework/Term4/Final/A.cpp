/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-05 14:03:51
 ************************************************************************/

#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<assert.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dis[1<<22],par[1<<22];
string str;
int strtoi(string str)
{
    int s=0;
    for(int i=0;i<5;i++)
    {
        s=s*16;
        if(str[i]>='0'&&str[i]<='9') s+=str[i]-'0';
        else s+=str[i]-'A'+10;
    }
    return s;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>str;
        a[i]=strtoi(str);
        //printf("%x\n",a[i]);
    }
    fill(dis,dis+(1<<20),INF);
    queue<int> que;
    memset(par,-1,sizeof(par));
    for(int i=0;i<n;i++)
    {
        if(dis[a[i]]!=INF)
        {
            puts("0");
            return 0;
        }
        dis[a[i]]=0;
        par[a[i]]=a[i];
        que.push(a[i]);
    }
    int ans=INF;
    while(!que.empty())
    {
        int p=que.front();
        que.pop();
        for(int j=0;j<20;j++)
        {
            int to=((p>>j)&1)?p-(1<<j):p+(1<<j);
            //printf("%x\n",to);
            if(par[to]==par[p]) continue;
            if(dis[to]!=INF) ans=min(ans,dis[p]+dis[to]+1);
            else
            {
                dis[to]=dis[p]+1;
                par[to]=par[p];
                que.push(to);
            }
        }
    }
    assert(ans!=INF);
    printf("%d\n",ans);
    return 0;
}

