/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-05 13:18:57
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
typedef long double db;
int T;
db N,a,L;
const db PI=acos(-1.0);
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%Lf%Lf%Lf",&N,&a,&L);
        db ang=PI*(N-2)/N;
        db mult=sin(ang/2);
        mult=mult*mult;
        db alpha=2*PI/N;
        db R=a/2/sin(alpha/2);
        db h=sqrt(R*R-(a/2)*(a/2));
        db Area=N*a*h/2;
        int cnt=0;
        while(Area>L)
        {
            Area*=mult;
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

