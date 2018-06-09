/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-05-31 14:22:51
 ************************************************************************/

#include<bits/stdc++.h>
#pragma GCC optimize(3)
#define MAXN 16
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
double winr[MAXN][MAXN];
double rate[4][MAXN];
int main()
{
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++)
            scanf("%lf",&winr[i][j]);
    for(int i=0;i<8;i++)
    {
        rate[0][i*2]=winr[i*2][i*2+1];
        rate[0][i*2+1]=winr[i*2+1][i*2];
    }
    for(int i=0;i<4;i++)
    {
        rate[1][i*4]=rate[0][i*4]*(rate[0][i*4+2]*winr[i*4][i*4+2]+rate[0][i*4+3]*winr[i*4][i*4+3]);
        rate[1][i*4+1]=rate[0][i*4+1]*(rate[0][i*4+2]*winr[i*4+1][i*4+2]+rate[0][i*4+3]*winr[i*4+1][i*4+3]);
        rate[1][i*4+2]=rate[0][i*4+2]*(rate[0][i*4]*winr[i*4+2][i*4]+rate[0][i*4+1]*winr[i*4+2][i*4+1]);
        rate[1][i*4+3]=rate[0][i*4+3]*(rate[0][i*4]*winr[i*4+3][i*4]+rate[0][i*4+1]*winr[i*4+3][i*4+1]);
    }
    for(int i=0;i<4;i++)
    {
        int id;
        if(i==0) id=4;
        if(i==1) id=0;
        if(i==2) id=12;
        if(i==3) id=8;
        for(int j=0;j<4;j++)
            for(int k=id;k<id+4;k++)
                rate[2][i*4+j]+=rate[1][i*4+j]*rate[1][k]*winr[i*4+j][k];
    }
    for(int i=0;i<2;i++)
    {
        int id;
        if(i==0) id=8; else id=0;
        for(int j=0;j<8;j++)
            for(int k=id;k<id+8;k++)
                rate[3][i*8+j]+=rate[2][i*8+j]*rate[2][k]*winr[i*8+j][k];
    }
    for(int i=0;i<16;i++)
    {
        printf("%.10f",rate[3][i]);
        if(i==15) printf("\n"); else printf(" ");
    }
    return 0;
}

