#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#define MAXN 10000
#define INF 100000000
using namespace std;
typedef pair<int,int> P;
int prime[MAXN],x,y,h;
int main()
{
    scanf("%d",&h);
    for(int k=1;k<=h;k++)
    {
    fill(prime,prime+MAXN,0);
    prime[0]=prime[1]=INF;
    for(int i=2;i<MAXN;i++)
    {
        if(prime[i]==0)
        {
            for(int j=2*i;j<MAXN;j+=i)
                prime[j]=INF;
        }
    }
    scanf("%d %d",&x,&y);
    if(x==y)
    {
        printf("0\n");
        continue;
    }
    queue<P> que;
    while(que.size()) que.pop();
    que.push(P(x,0));
    while(que.size())
    {
        P p=que.front();
        que.pop();
        if(p.first==y) break;
        for(int i=1;i<=4;i++)
        {
            for(int j=0;j<=9;j++)
            {
              if(i==p.second||(i==4&&j==0)) continue;
              int z;
              if(i==1) z=(p.first/10)*10+j;
              else if(i==2) z=(p.first/100)*100+10*j+p.first%10;
              else if(i==3) z=(p.first/1000)*1000+100*j+p.first%100;
              else z=1000*j+p.first%1000;
              if(z==p.first) continue;
              if(prime[z]==0)
              {
                  prime[z]=prime[p.first]+1;
                  que.push(P(z,i));
              }
            }
        }
    }
    printf("%d\n",prime[y]);
    }
}