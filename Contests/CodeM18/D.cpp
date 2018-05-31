/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-31 14:38:30
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXM 6
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define eps 1e-10
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<long double,int> P;
int n,m,k,C;
int score[MAXM][MAXN],weight[MAXM];
bool mark[MAXN];
long double now[MAXN];
P rating[MAXN];
int cnt[MAXN];
int main()
{
    scanf("%d%d%d%d",&n,&m,&k,&C);
    memset(mark,false,sizeof(mark));
    int sum=0;
    for(int i=0;i<m;i++) 
        scanf("%d",&weight[i]);
    int pid=-1,rid=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d",&score[j][i]);
            if(score[j][i]==-1) 
            {
                pid=i;
                rid=j;
            }
        }
    for(int i=0;i<m;i++)
    {
        if(i==rid) continue;
        int res=0;
        for(int j=0;j<n;j++)
            res=max(res,score[i][j]);
        if(res==0) continue;
        for(int j=0;j<n;j++)
            now[j]+=(long double)score[i][j]/res*weight[i];
    }
    for(int i=0;i<=C;i++)
    {
        score[rid][pid]=i;
        int res=0;
        for(int j=0;j<n;j++)
            res=max(res,score[rid][j]);
        for(int j=0;j<n;j++)
        {
            rating[j].F=now[j]+(res==0?0:(long double)score[rid][j]/res*weight[rid]);
            rating[j].S=j;
        }
        sort(rating,rating+n);
        for(int j=n-1;j>n-1-k;j--)
            cnt[rating[j].S]++;
        if(n==k) continue;
        if(rating[n-k].F==rating[n-1-k].F)
        {
            int lid=INF,rid=-INF;
            for(int i=0;i<n;i++)
                if(abs(rating[i].F-rating[n-k].F)<eps)
                {
                    lid=min(lid,i);
                    rid=max(rid,i);
                }
            for(int i=lid;i<=rid;i++)
                mark[rating[i].S]=true;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(mark[i]) printf("3");
        else if(cnt[i]==C+1) printf("1");
        else if(cnt[i]==0) printf("2");
        else printf("3");
        printf("\n");
    }
    return 0;
}

