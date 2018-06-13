/*************************************************************************
    > File Name: 183.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-13 17:35:36
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
const double e=2.718281828459;
int n,k,a[MAXN];
int main()
{
    int ans=0;
    for(int i=5;i<=10000;i++)
    {
        int id,id1,id2;
        id1=floor(i/e),id2=ceil(i/e);
        if(id1*(log(i)-log(id1))>id2*(log(i)-log(id2))) id=id1; else id=id2;
        //printf("%d %d\n",i,id);
        while(id%2==0) id/=2;
        while(id%5==0) id/=5;
        if(i%id==0) ans-=i; else ans+=i;
        //printf("%d\n",ans);
    }
    printf("%d\n",ans);
    return 0;
}

