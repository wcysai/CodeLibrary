/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-05 14:06:51
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
int n,p,t;
int main()
{
    scanf("%d%d%d",&n,&p,&t);
    int num=(t/9)*3;
    if(t%9==5) num++;
    else if(t%9==7) num++;
    else if(t%9==8) num+=2;
    int l=1+num,r=n+num;
    if(p<l||p>r) puts("-1");
    else printf("%d\n",p-l+1);
    return 0;
}

