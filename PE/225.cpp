/*************************************************************************
    > File Name: 225.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-13 17:52:35
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
int cnt=0;
int main()
{
    for(int i=27;;i+=2)
    {
        int a=1,b=1,c=1;
        bool f=true;
        for(int j=1;j<=100000;j++)
        {
            int t=(a+b+c)%i;
            a=b;b=c;c=t;
            if(t==0) 
            {
                f=false;
                break;
            }
        }
        if(f)
        {
            cnt++;
            printf("%d\n",i);
        }
        if(cnt==124) break;
    }
    return 0;
}

