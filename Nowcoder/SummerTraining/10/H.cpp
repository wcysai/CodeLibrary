/*************************************************************************
    > File Name: H.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-19 15:54:10
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
int t,a,b,c,d;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int x1=1,x2=1,y1=0,y2=0;
        for(int i=1;i<=100;i++)
        {
            printf("%d %d %d %d\n",x1,y1,x2,y2);
            if(b*x1>=a*(y1+1)) y1++; else x1++;
            if(d*x2>=c*(y2+1)) y2++; else x2++;
        }
    }
    return 0;
}

