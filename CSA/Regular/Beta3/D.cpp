/*************************************************************************
    > File Name: Beta3D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-10 16:48:21
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
    int s=0,cnt=0,save=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='A')
        {
            cnt++;
            s^=save;
            save=0;
        }
        else save++;
    }
    s^=save;
    if(cnt%2==0) puts("-1");
    else if(s==0) puts("B");
    else puts("A");
    return 0;
}

