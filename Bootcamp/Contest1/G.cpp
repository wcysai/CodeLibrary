/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 19:44:25
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
string str;
int cnt[4];
int main()
{
    cin>>str;
    n=str.size();
    int cur=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='L') cur=(cur+3)%4; else {cur=(cur+1)%4; cnt[cur]++;}
        if(cur==0)
        {
            if(cnt[0]&&cnt[1]&&cnt[2]&&cnt[3]) ans++;
            cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
        }
    }
    printf("%d\n",ans);
    return 0;
}

