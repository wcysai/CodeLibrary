/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-30 04:50:36
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
vector<int> v;
int main()
{
    for(int k=1;k*(k+1)/2<=INF;k++) v.push_back(k*(k+1)/2);
    scanf("%d",&n);
    for(int i=0;i<(int)v.size();i++)
    {
        if(v[i]>n) break;
        int rest=n-v[i];
        if(upper_bound(v.begin(),v.end(),rest)-lower_bound(v.begin(),v.end(),rest)!=0) {puts("YES"); return 0;}
    }
    puts("NO");
    return 0;
}

