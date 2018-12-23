/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-22 20:06:44
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
int n,k,a[MAXN];
int main()
{
    bool f=true;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(a[i]%2==1) f=false;
    }
    if(!f) puts("first"); else puts("second");
    return 0;
}

