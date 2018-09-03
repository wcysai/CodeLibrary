/*************************************************************************
    > File Name: I.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-01 12:51:19
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define MAXM 20005
#define INF 1000000000
#define MOD 1000000007
#define next __next
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m;
int a[MAXM];
int have[MAXN][15];
int cnt[MAXN];
int p[13]={3,4,5,6,7,8,9,10,11,12,13,1,2};
int next[14]={0,2,0,4,5,6,7,8,9,10,11,12,13,1};
int main()
{
    scanf("%d",&T);
    int kase=0;
    while(T--)
    {
        kase++;
        memset(cnt,0,sizeof(cnt));
        memset(have,0,sizeof(have));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) scanf("%d",&a[i]);
        int tot=1;
        for(int i=1;i<=n;i++)
        {
            if(tot>m) break;
            for(int j=1;j<=5;j++)
            {
                cnt[i]++;
                have[i][a[tot]]++;
                tot++;
                if(tot>m) break;
            }
        }
        int now=1,last=0,cc=0,winner=0;
        while(true)
        {
            if(cc==n-1)
            {
                //puts("draw");
                for(int i=1;i<=n;i++)
                {
                    if(tot>m) break;
                    cnt[i]++;
                    have[i][a[tot]]++;
                    tot++;
                }
                last=0;cc=0;
            }
            if(last==0)
            {
                cnt[now]--;
                if(cnt[now]==0) {winner=now; break;}
                for(int i=0;i<13;i++)
                {
                    if(have[now][p[i]]>0)
                    {
                        have[now][p[i]]--;
                        last=p[i];
                        //printf("%d %d\n",now,p[i]);
                        break;
                    }
                }
                cc=0;
                assert(last!=0);
            }
            else if(last!=2)
            {
                if(have[now][next[last]]>0)
                {
                    cnt[now]--;
                    if(cnt[now]==0) {winner=now; break;}
                    have[now][next[last]]--;cc=0;
                    last=next[last];
                    //printf("%d %d\n",now,next[last]);
                }
                else if(have[now][2]>0)
                {
                    cnt[now]--;
                    if(cnt[now]==0) {winner=now; break;}
                    last=2;
                    have[now][2]--;cc=0;
                   // printf("%d %d\n",now,2);
                }
                else 
                {   
                    cc++;
                    //printf("%d pass\n",now);
                }
            }
            else {cc++; /*printf("%d pass\n",now);*/}
            now++;if(now>n) now-=n;
        }
        printf("Case #%d:\n",kase);
        for(int i=1;i<=n;i++)
        {
            if(winner==i)
            {
                puts("Winner");
                continue;
            }
            int sum=0;
            for(int j=1;j<=13;j++) sum+=have[i][j]*j;
            printf("%d\n",sum);
        }
    }
    return 0;
}

