#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#define MAXN 1000
using namespace std;
int n;
priority_queue<int,vector<int>,greater<int> > que;
int main()
{
   while(scanf("%d",&n)==1)
   {
      while(!que.empty()) que.pop();
   int x,y;
   for(int i=0;i<n;i++)
   {
       scanf("%d %d",&x,&y);
       que.push(x);
   }
   int cnt=0;
   while(que.size()>1)
   {
       x=que.top();
       que.pop();
       y=que.top();
       que.pop();
       cnt+=x+y;
       que.push(x+y);
   }
   printf("%d\n",cnt);
   }
   return 0;
}
