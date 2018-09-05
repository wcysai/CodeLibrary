/*************************************************************************
    > File Name: 75A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-04 12:15:00
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
int D,T,v1,v2;
int main()
{
    scanf("%d%d%d%d",&D,&T,&v1,&v2);
    if(v1>v2&&(T*(v1-v2)>=D))
    {
        printf("%d\n",(D-1)/(v1-v2)+1);
        return 0;
    }
    D-=T*(v1-v2);
    printf("%d\n",T+(D-1)/v1+1);
    return 0;
}

