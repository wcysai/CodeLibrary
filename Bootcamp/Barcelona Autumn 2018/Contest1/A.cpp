/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 19:30:30
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
int n;
int main()
{
    int s=0,cur=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x;scanf("%d",&x);
        s^=x;cur|=(x&1);
    }
    if((s==1)||(s==0&&cur==0)) puts("Bob"); else puts("Alice");
    return 0;
}

