/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-03 18:14:15
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
int solution (int N)
{
    if(N==0) return 0;
    vector<int> v;
    v.clear();
    while(N)
    {
        v.push_back(N%10);
        N=N/10;
    }
    int ans=0;
    sort(v.begin(),v.end());
    for(int i=(int)v.size()-1;i>=0;i--) ans=ans*10+v[i];
    return ans;
}
