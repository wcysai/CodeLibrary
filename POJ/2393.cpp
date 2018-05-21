#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 20
#define INF 100000000
using namespace std;
struct alw
{
    int denom;
    int amount;
};
int n,c,way[MAXN],cnt;
alw bessie[MAXN];
bool cmp(alw m,alw n)
{
    return m.denom<n.denom;
}
bool findway()
{
    for(int i=0;i<n;i++)
      way[i]=0;
    int t=c;
    for(int i=n-1;i>=0;i--)
    {
        if(t>=bessie[i].denom&&bessie[i].amount>0)
        {
            way[i]=min(t/bessie[i].denom,bessie[i].amount);
            t-=bessie[i].denom*way[i];
        }
    }
    if(t>0)
    {
    for(int i=0;i<n;i++)
    {
      if(t>0&&bessie[i].amount>way[i])
      {
          int x=min(bessie[i].amount,(t-1)/bessie[i].denom+1);
          way[i]+=x;
          t-=x*bessie[i].denom;
      }
      if (t<=0) break;
    }
    }
    if(t>0) return false;
    else return true;
}
void detm()
{
    int rec;
    rec=INF;
    for(int i=n-1;i>=0;i--)
        if(way[i]>0) rec=min(rec,bessie[i].amount/way[i]);
    cnt+=rec;
    for(int i=n-1;i>=0;i--)
        bessie[i].amount-=rec*way[i];
    return;
}
int main()
{
    scanf("%d %d",&n,&c);
    for(int i=0;i<n;i++)
        scanf("%d %d",&bessie[i].denom,&bessie[i].amount);
    sort(bessie,bessie+n,cmp);
    cnt=0;
    int j=0;
    while(bessie[j].denom>=c)
    {
        cnt+=bessie[j].amount;
        bessie[j].amount=0;
        j++;
    }
    while(findway())
        detm();
    printf("%d\n",cnt);
    return 0;
}