/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-01 19:37:40
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
P a[MAXN];
vector<int> v;
int fact[MAXN];
int cntx[MAXN],cnty[MAXN];
int main()
{
    fact[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);v.clear();
        memset(cntx,0,sizeof(cntx));memset(cnty,0,sizeof(cnty));
        for(int i=0;i<2*n;i++)
        {
            scanf("%d%d",&a[i].F,&a[i].S);
            v.push_back(a[i].F);v.push_back(a[i].S);
        }
        sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());
        for(int i=0;i<2*n;i++)
        {
            int x=lower_bound(v.begin(),v.end(),a[i].F)-v.begin()+1;
            int y=lower_bound(v.begin(),v.end(),a[i].S)-v.begin()+1;
            a[i].F=x;a[i].S=y;
            cntx[x]++;cnty[y]++;
        }
        int curx=0,sumx=0;
        for(int i=1;i<=400000;i++) {sumx+=cntx[i]; if(sumx>=n){curx=i; break;}}
        if(sumx>n) {puts("0"); continue;}
        int cury=0,sumy=0;
        for(int i=1;i<=400000;i++) {sumy+=cnty[i]; if(sumy>=n){cury=i; break;}}
        if(sumy>n) {puts("0"); continue;}
        int cnt=0;
        for(int i=0;i<2*n;i++) if(a[i].F<=curx&&a[i].S<=cury) cnt++;
        printf("%lld\n",1LL*fact[cnt]*fact[n-cnt]%MOD);
    }
    return 0;
}

