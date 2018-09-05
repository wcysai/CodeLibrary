/*************************************************************************
    > File Name: 80A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-23 23:00:31
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
    for(int i=0;i<16;i++) scanf("%d",&a[i]);
    int cnt=4;
    for(int i=4;i<16;i++) if(a[i]+300>a[3]) cnt++; else break;
    printf("%d\n",cnt);
    return 0;
}

