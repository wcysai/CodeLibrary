/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-06 19:13:36
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
int n,q,a[MAXN];
string str;
map<int,int> mp;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]=i;
    }
    scanf("%d",&q);
    int s=0,t=n+1;
    for(int i=1;i<=q;i++)
    {
        cin>>str;
        int x;
        scanf("%d",&x);
        if(str[0]=='F') {a[x]=s; s--;}
        else {a[x]=t; t++;}
    }
    for(int i=1;i<=n;i++) mp[a[i]]=i;
    for(auto it=mp.begin();it!=mp.end();it++)
        if(it==mp.begin()) printf("%d",it->S); else printf(" %d",it->S);
    puts("");
    return 0;
}

