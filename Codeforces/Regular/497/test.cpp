/*************************************************************************
    > File Name: test.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-13 23:39:19
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
int x,y,z;
set< multiset<int> > s;
int main()
{
    while(scanf("%d%d%d",&x,&y,&z)==3)
    {
        s.clear();
    for(int i=1;i<=x;i++)
        for(int j=1;j<=y;j++)
            for(int k=1;k<=z;k++)
            {
                if(x%i==0&&y%j==0&&z%k==0)
                {
                    multiset<int> ss;
                    ss.insert(i);ss.insert(j);ss.insert(k);
                    s.insert(ss);
                }
            }
    printf("%d\n",(int)s.size());
    }
    return 0;
}

