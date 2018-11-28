/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-28 22:38:22
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x,y,d;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&x,&y,&d);
        bool f=false;
        if((y-1)%d==0) f=true;
        else if((n-y)%d==0) f=true;
        else if(abs(x-y)%d==0) f=true;
        if(!f) puts("-1");
        else
        {
            int ans=INF;
            if(abs(x-y)%d==0) ans=min(ans,abs(x-y)/d);
            if(y%d==1) ans=min(ans,(x-1-1+d)/d+abs(y-1)/d);
            if((n-y)%d==0) ans=min(ans,(n-x-1+d)/d+abs(n-y)/d);
            printf("%d\n",ans);
        }
    }
    return 0;
}

