/*************************************************************************
    > File Name: MAGICHF.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-11 16:41:29
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
int T,N,X,S;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&N,&X,&S);
        for(int i=0;i<S;i++)
        {
            int A,B;
            scanf("%d%d",&A,&B);
            if(A==X) X=B;
            else if(B==X) X=A;
        }
        printf("%d\n",X);
    }
    return 0;
}

