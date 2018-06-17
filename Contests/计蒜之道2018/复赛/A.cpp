/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-17 13:59:56
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
int t,n,k;
P a[MAXN];
bool cmp(P x,P y)
{
    return x.F*y.S+x.S<y.F*x.S+y.S;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i].F);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i].S);
        //for(int i=0;i<n;i++)
          //  printf("%d %d\n",a[i].F,a[i].S);
        sort(a,a+n,cmp);
        int now=k;
        for(int i=0;i<n;i++)
            now=(now*a[i].F+a[i].S)%10;
        printf("%d\n",now);
    }
    return 0;
}

