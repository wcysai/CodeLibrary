/*************************************************************************
    > File Name: 80B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-25 01:10:05
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
int a,perm[9],b;
int main()
{
    scanf("%d%d",&a,&b);
    int t=0;
    while(a>0)
    {
        perm[t++]=a%10;
        a=a/10;
    }
    int ans=-1;
    sort(perm,perm+t);
    do
    {
        if(perm[0]==0) continue;
        int s=0;
        for(int i=0;i<t;i++) s=s*10+perm[i];
        if(s<=b&&s>=ans) ans=s;
    }while(next_permutation(perm,perm+t));
    printf("%d\n",ans);
    return 0;
}

