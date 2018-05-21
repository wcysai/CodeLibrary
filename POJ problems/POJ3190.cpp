#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define MAXN 50020
using namespace std;
struct node
{
    int num;
    int left;
    int right;
    int identi;
};
struct stall
{
    int num;
    int endt;
};

bool cmp(node x,node y)
{
    if(x.left!=y.left) return x.left<y.left;
    return x.right<y.right;
}
struct cmp2
{
    bool operator()(const stall &x,const stall &y)
       {
            return x.endt>y.endt;
       }
};
bool cmp3(node x,node y)
{
    return x.num<y.num;
}
int main()
{
    int n;
    node cow[MAXN];
    scanf("%d",&n);
    priority_queue<stall,vector<stall>,cmp2> que;
    while(que.size()) que.pop();
    for(int i=0;i<n;i++)
    {
      scanf("%d %d",&cow[i].left,&cow[i].right);
      cow[i].num=i+1;
    }
    sort(cow,cow+n,cmp);
    int k=0,cnt=0;
    while(k<n)
    {
        stall dummy;
        if(que.empty())
        {
            stall cowt;
            cnt++;
            cowt.num=cnt;
            cowt.endt=cow[k].right;
            cow[k].identi=cnt;
            que.push(cowt);
        }
        else
        {
            dummy=que.top();
            if(cow[k].left<=dummy.endt)
            {
              stall cowt;
              cnt++;
              cowt.num=cnt;
              cowt.endt=cow[k].right;
              cow[k].identi=cnt;
              que.push(cowt);
          }
          else
          {
            dummy.endt=cow[k].right;
            cow[k].identi=dummy.num;
            que.pop();
            que.push(dummy);
          }
        }
        k++;
    }
    printf("%d\n",cnt);
    sort(cow,cow+n,cmp3);
    for(int i=0;i<n;i++)
        printf("%d\n",cow[i].identi);
    return 0;
}