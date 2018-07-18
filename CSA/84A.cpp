/*************************************************************************
    > File Name: 84A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-18 23:00:52
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
int n,k,a[MAXN],b[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
    for(int i=0;i<n;i++)
    {
        int cnt=b[i];
        if(a[i]==1)
        {
            int t=i+1;
            while(t<n&&a[t]==1) cnt+=b[t],t++;
        }
        else continue;
        if(cnt>=k) {printf("%d\n",i+1); return 0;}
    }
    puts("-1");
    return 0;
}

