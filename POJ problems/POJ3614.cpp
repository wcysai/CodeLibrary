#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAXN 2505
using namespace std;
struct cow
{
    int maxspf;
    int minspf;
};
struct lotion
{
    int spf;
    int cover;
};
bool cmp(lotion x,lotion y)
{
    return x.spf<y.spf;
}
bool cmp2(cow x,cow y)
{
    return x.minspf<y.minspf;
}
int main()
{
    cow a[MAXN];
    lotion b[MAXN];
    int c,l,k,cnt;
    priority_queue<int,vector<int>,greater<int> >que;
    while(que.size()) que.pop();
    scanf("%d %d",&c,&l);
    for(int i=0;i<c;i++)
      scanf("%d %d",&a[i].minspf,&a[i].maxspf);
    for(int i=0;i<l;i++)
      scanf("%d %d",&b[i].spf,&b[i].cover);
    sort(b,b+l,cmp);
    sort(a,a+c,cmp2);
    k=0;
    cnt=0;
    for(int i=0;i<l;i++)
    {
        while(a[k].minspf<=b[i].spf&&k<c)
        {
            que.push(a[k].maxspf);
            k++;
        }
        while(que.size()&&b[i].cover>0)
        {
            if(que.top()>=b[i].spf)
            {
            cnt++;
            b[i].cover--;
            }
            que.pop();
        }
    }
    printf("%d\n",cnt);
    return 0;
}