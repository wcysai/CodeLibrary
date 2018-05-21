#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>
#define MAXN 10002
using namespace std;
struct fuel
{
    int dis;
    int capa;
};
bool cmp(fuel m,fuel n)
{
    return m.dis<n.dis;
}
int main()
{
    int n,l,p,j,k,st,cnt;
    fuel a[MAXN];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&a[i].dis,&a[i].capa);
    scanf("%d %d",&l,&p);
    for(int i=0;i<n;i++)
        a[i].dis=l-a[i].dis;
    sort(a,a+n,cmp);
    priority_queue <int> que;
    st=0;
    cnt=0;
    k=0;
    while(que.size()) que.pop();
    while(true)
    {
        k+=p;
        if (k>=l) break;
        cnt++;
        while(a[st].dis<=k)
        {
            que.push(a[st].capa);
            st++;
        }
        if (que.empty())
        {
            puts("-1");
            return 0;
        }
        p=que.top();
        que.pop();
    }
    printf("%d\n",cnt);
    return 0;
}