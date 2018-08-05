/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-05 12:05:44
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
int T,N;
int main()
{
    scanf("%d",&T);
    int tot=0;
    while(T--)
    {
        tot++;
        printf("Case %d: ",tot);
        scanf("%d",&N);
        if(N==6||N==28||N==496||N==8128)
        {
            printf("%d = ",N);
            for(int i=1;i<=N/2;i++)
            {
                if(N%i==0)
                {
                    if(i!=N/2) printf("%d + ",i);
                    else printf("%d\n",i);
                }
            }
        }
        else puts("Not perfect.");
    }
    return 0;
}

