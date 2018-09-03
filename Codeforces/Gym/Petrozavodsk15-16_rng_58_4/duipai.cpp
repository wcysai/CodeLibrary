/*************************************************************************
    > File Name: duipai.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-02 18:21:43
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
int n,mx,a[MAXN],c[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&c[i]);a[i]--;
        mx=max(a[i],mx);
    }
    int ans=0;
    for(int i=1;i<=mx;i++)
    {
        bool f=true;
        for(int j=1;j<=n-1;j++)
        {
            if(c[j]==c[j+1]&&a[j]/i!=a[j+1]/i) f=false;
            if(c[j]!=c[j+1]&&a[j]/i==a[j+1]/i) f=false;
        }
        if(f) {printf("%d\n",i); ans++;}
    }
    printf("%d\n",ans);
    return 0;
}

