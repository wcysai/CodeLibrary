/*************************************************************************
    > File Name: 84B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-18 23:00:59
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
int n;
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    int ans=0;
    int l=0,r=0,cnt=0;
    while(r<n&&cnt<3) 
    {
        if(str[r]=='1') cnt++;
        r++;
    }
    if(cnt==3) r--,cnt--;
    //printf("%d %d\n",l,r);
    ans=r-l;
    while(l<n&&r<n)
    {
        if(str[l]=='1') cnt--;
        l++;
        while(r<n&&cnt<3)
        {
            if(str[r]=='1') cnt++;
            r++;
        }
        if(cnt==3) cnt--,r--;
        ans=max(ans,r-l);
    }
    printf("%d\n",ans+1);
    return 0;
}

