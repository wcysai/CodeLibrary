#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
P compute(int x,int y,int dis)
{
    if(x>y) return compute(y,x,dis);
    int s=x*dis;
    if(y-x>dis) return P(-1,-1);
    int d=dis-(y-x);
    s+=d*d/2;
    int dif=max(x,d/2),adj=(dis-dif)*dif;
    int s1=s-adj;
    dif=d/2,adj=(dis-dif)*dif;
    int s2=s+d*(y-x)+adj;
    return P(s1-y,s2-y);
}
int t,n,m;
P a[MAXN];
int main()
{
    scanf("%d%d%d",&t,&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S);
        a[i].F--;
    }
    sort(a,a+m);
    int left=compute(max(0,a[0].S-a[0].F),a[0].S,a[0].F).F+compute(max(0,n-1-a[m-1].F-a[m-1].S),a[m-1].S,n-1-a[m-1].F).F;
    int right=compute(a[0].S+a[0].F,a[0].S,a[0].F).S+compute(n-1-a[m-1].F+a[m-1].S,a[m-1].S,n-1-a[m-1].F).S;
    printf("%d %d\n",left,right);
    return 0;
}
