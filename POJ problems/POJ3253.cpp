#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#define MAXN 20005
using namespace std;
int main()
{
    int n;
    long long x,y,sum;
    scanf("%d",&n);
    priority_queue<long long,vector<long long>,greater<long long> >que;
    for(int i=0;i<n;i++)
    {
      scanf("%lld",&x);
      que.push(x);
    }
    sum=0;
    while(que.size()>1)
    {
        x=que.top();
        que.pop();
        y=que.top();
        que.pop();
        sum+=x+y;
        que.push(x+y);
    }
    printf("%lld",sum);
}