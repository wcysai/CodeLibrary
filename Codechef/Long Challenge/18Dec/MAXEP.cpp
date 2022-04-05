/*************************************************************************
    > File Name: MAXEP.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-14 18:12:00
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
int N,c;
void solve(int l,int r)
{
    if(l==r) {printf("3 %d\n",l+1); fflush(stdout); return;}
    int mid=l+(r-l)/8+1;
    assert(mid>l);assert(mid<=r);
    printf("%d %d\n",1,mid);fflush(stdout);
    int x;
    scanf("%d",&x);
    assert(x!=-1);
    if(x==0) solve(mid,r);
    else
    {
        printf("2\n");fflush(stdout);
        solve(l,mid-1);
    }
    return;
}
int main()
{
    scanf("%d%d",&N,&c);
    solve(0,N);
    return 0;
}

