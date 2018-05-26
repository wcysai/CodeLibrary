/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-26 20:02:39
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,sum1[MAXN],sum2[MAXN];
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<n;i++)
        sum1[i+1]=str[i]=='W'?sum1[i]+1:sum1[i];
    for(int i=n;i>=1;i--)
        sum2[i]=str[i-1]=='E'?sum2[i+1]+1:sum2[i+1];
    int ans=INF;
    for(int i=1;i<=n;i++)
        ans=min(ans,sum1[i-1]+sum2[i+1]);
    printf("%d\n",ans);
    return 0;
}

