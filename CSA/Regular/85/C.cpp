/*************************************************************************
    > File Name: 85C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-01 23:14:04
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
struct node
{
    int val,pow2,pow3;
};
int n;
node A,B;
node a[MAXN];
bool cmp(node x,node y)
{
    if(x.pow2!=y.pow2) return x.pow2>y.pow2;
    return x.pow3<y.pow3;
}
vector<int> ans;
int main()
{
    bool f=true;
    scanf("%d%d%d",&n,&A.val,&B.val);
    int t=A.val;
    while(t%2==0) {t=t/2; A.pow2++;}
    while(t%3==0) {t=t/3; A.pow3++;}
    int rem=t;
    t=B.val;
    while(t%2==0) {t=t/2; B.pow2++;}
    while(t%3==0) {t=t/3; B.pow3++;}
    if(t!=rem) f=false;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].val);
        t=a[i].val;
        while(t%2==0) {t=t/2; a[i].pow2++;}
        while(t%3==0) {t=t/3; a[i].pow3++;}
        if(t!=rem) f=false;
    }
    sort(a+1,a+n+1,cmp);
    a[0]=A;a[n+1]=B;
    ans.push_back(A.val);int p2=A.pow2,p3=A.pow3,now=A.val;
    for(int i=1;i<=n+1;i++)
    {
        if(a[i].pow2>p2) {f=false; break;}
        if(a[i].pow3<p3) {f=false; break;}
        while(a[i].pow2<p2) {now/=2; p2--; ans.push_back(now);}
        while(a[i].pow3>p3) {now*=3; p3++; ans.push_back(now);}
    }
    if(!f) puts("-1");
    else for(int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
    return 0;
}

