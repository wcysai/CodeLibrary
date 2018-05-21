#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAXN 300005
struct cow
{
    int csat;
    int aid;
};
bool cmp(cow x,cow y)
{
    return x.csat<y.csat;
}
using namespace std;
int main()
{
    int n,c,k;
    int f,sum,ans;
    cow a[MAXN];
    int res[MAXN];
    scanf("%d %d %d",&n,&c,&f);
    for(int i=0;i<c;i++)
        scanf("%d %d",&a[i].csat,&a[i].aid);

    priority_queue<int> que1;
    priority_queue<int> que2;
    sort(a,a+c,cmp);
    while(que1.size()) que1.pop();
    while(que2.size()) que2.pop();
    memset(res,0,sizeof(res));
    sum=0;
    ans=-1;
    for(int i=0;i<=n/2-1;i++)
    {
        que1.push(a[i].aid);
        sum+=a[i].aid;
    }
    sum+=a[n/2].aid;
    k=n/2;
    res[k]=sum;
    while(k<c-1-n/2)
    {
        que1.push(a[k].aid);
        sum+=a[k+1].aid;
        sum-=que1.top();
        que1.pop();
        k++;
        res[k]=sum;
    }
    sum=0;
     for(int i=c-1;i>=c-n/2;i--)
    {
        que2.push(a[i].aid);
        sum+=a[i].aid;
    }
    sum+=a[c-1-n/2].aid;
    k=c-1-n/2;
    res[k]+=sum;
    while(k>n/2)
    {
        que2.push(a[k].aid);
        sum+=a[k-1].aid;
        sum-=que2.top();
        que2.pop();
        k--;
        res[k]+=sum;
    }
    for(int i=n/2;i<=c-1-n/2;i++)
    {
        res[i]-=a[i].aid;
        if(res[i]<=f) ans=a[i].csat;
    }
    printf("%d\n",ans);
}