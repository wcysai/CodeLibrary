/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 17:48:07
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
char str[3];
int main()
{
    scanf("%d",&n);
    int l=1,r=n+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        printf("? %d\n",mid);
        fflush(stdout);
        scanf("%s",str);
        if(str[0]=='<') r=mid; else l=mid;
    }
    printf("! %d\n",l);
    return 0;
}

