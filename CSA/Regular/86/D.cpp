/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-05 14:44:55
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
typedef long double db;
db H;
int Q;
struct Leak
{
    int t,h;
}a[MAXN];
bool cmp(Leak p,Leak q)
{
    if(p.t!=q.t) return p.t<q.t;
    return p.h<q.h;
}
int main()
{
    scanf("%Lf%d",&H,&Q);
    int mx=INF;
    for(int i=0;i<Q;i++) 
    {
        scanf("%d%d",&a[i].t,&a[i].h);
        mx=min(mx,a[i].h);
    }
    sort(a,a+Q,cmp);
    if(mx>0) {puts("-1"); return 0;}
    db curt=0.0,nxtt;
    int num=0;
    priority_queue<int> pque;
    for(int i=0;i<Q;i++)
    {
        printf("%d %d %Lf\n",a[i].t,a[i].h,H);
        nxtt=a[i].t-curt;
        while(pque.size()&&H-pque.top()<=nxtt*num)
        {
            db lt=(H-pque.top())/num;
            nxtt-=lt;curt+=lt;H-=lt*num;
            num--;pque.pop();
        }
        if(nxtt*num>=H) 
        {
            if(num==0) printf("%.10Lf\n",curt);
            else printf("%.10Lf\n",H/num+curt);
            return 0;
        }
        curt+=nxtt;
        H-=nxtt*num;
        if(a[i].h<=H) {num++; pque.push(a[i].h);} 
    }
    while(H>0)
    {
        db lt=(H-pque.top())/num;
        nxtt-=lt;curt+=lt;H-=lt*num;
        num--;pque.pop();
    }
    printf("%.10Lf\n",curt);
    return 0;
}

