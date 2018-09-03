/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-01 12:30:18
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,k,st[MAXN];
int grid[MAXN][MAXM];
vector<P> v;
int main()
{
    scanf("%d",&T);
    int kase=0;
    while(T--)
    {
        kase++; 
        v.clear();
        scanf("%d%d",&n,&m);


        int t=0;
	    for(int i=0;i<n;i++)
	    {
		    while(t>0&&h[st[t-1]]>=h[i]) t--;
		    L[i]=t==0?0:(st[t-1]+1);
		    st[t++]=i;
	    }
	t=0;
	for(int i=n-1;i>=0;i--)
	{
		while(t>0&&h[st[t-1]]>=h[i]) t--;
		R[i]=t==0?n:st[t-1];
		st[t++]=i;
	}
    return 0;
}

