/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-05 12:55:29
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
int T,N;
double p;
ll x[MAXN],y[MAXN];
int main()
{
    scanf("%d",&T);
    srand(time(NULL));
    while(T--)
    {
        scanf("%d%lf",&N,&p);
        int num=(int)((ceil)(N*p));
        for(int i=0;i<N;i++) scanf("%lld%lld",&x[i],&y[i]);
        if(num<=2) {puts("Yes"); continue;}
        bool f=false;
        for(int i=0;i<400;i++)
        {
            int id1=rand()%N,id2=rand()%N;
            while(id1==id2) {id1=rand()%N;id2=rand()%N;}
            int cnt=2;
            for(int i=0;i<N;i++)
            {
                if(i==id1||i==id2) continue;
                if((x[i]-x[id1])*(y[i]-y[id2])-(x[i]-x[id2])*(y[i]-y[id1])==0) 
                {
                    //printf("%d %d %d\n",id1,id2,i);
                    cnt++;
                }
            }
            if(cnt>=num) {f=true; break;}
        }
        if(f) puts("Yes"); else puts("No");
    }
    return 0;
}

