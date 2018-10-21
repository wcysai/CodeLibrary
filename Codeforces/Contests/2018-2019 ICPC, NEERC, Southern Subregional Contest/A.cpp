/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-20 16:07:05
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
int d,s;
int m[5005];
int main()
{
    scanf("%d%d",&d,&s);
    int cur=1;
    for(int i=1;i<=5000;i++)
    {
        cur=cur%d;
        cur=cur*10;
    }
    return 0;
}

