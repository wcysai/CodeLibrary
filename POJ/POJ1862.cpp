#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    priority_queue<float> que;
    int n,p;
    float x,y;
    scanf("%d",&n);
    while(que.size()) que.pop();
    for(int i=0;i<n;i++)
    {
      scanf("%d",&p);
      que.push(p);
    }
    while(que.size()>1)
    {
        x=que.top();
        que.pop();
        y=que.top();
        que.pop();
        que.push(2*sqrt(x*y));
    }
    printf("%.3f",que.top());
    return 0;
}
