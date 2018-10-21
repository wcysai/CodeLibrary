/*************************************************************************
    > File Name: SURCHESS.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-08 12:45:44
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int N,M,Q,sum[4][MAXN][MAXN];
char str[MAXN][MAXN];
int need[MAXN];
int main()
{
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++) scanf("%s",str[i]+1);
    for(int i=1;i<=N;i++) 
        for(int j=1;j<=M;j++)
        {
            sum[0][i][j]=sum[0][i][j-1]+(str[i][j]=='1'&&((i+j)&1));
            sum[1][i][j]=sum[1][i][j-1]+(str[i][j]=='1'&&(!((i+j)&1)));
            sum[2][i][j]=sum[2][i][j-1]+(str[i][j]=='0'&&((i+j)&1));
            sum[3][i][j]=sum[3][i][j-1]+(str[i][j]=='0'&&(!((i+j)&1)));
        }

    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++)
            for(int k=0;k<4;k++)
                sum[k][i][j]+=sum[k][i-1][j];
    for(int i=1;i<=200;i++) need[i]=INF;
    for(int d=1;d<=min(N,M);d++)
        for(int i=1;i+d-1<=N;i++)
            for(int j=1;j+d-1<=M;j++)
            {
                int even,odd;
                if(d&1)
                {
                    if((i+j)&1) {even=d*d/2;odd=d*d-even;}
                    else {odd=d*d/2; even=d*d-odd;}
                }
                else {even=odd=d*d/2;}
                int odd0=sum[0][i+d-1][j+d-1]-sum[0][i-1][j+d-1]-sum[0][i+d-1][j-1]+sum[0][i-1][j-1];
                int even0=sum[1][i+d-1][j+d-1]-sum[1][i-1][j+d-1]-sum[1][i+d-1][j-1]+sum[1][i-1][j-1];
                int odd1=sum[2][i+d-1][j+d-1]-sum[2][i-1][j+d-1]-sum[2][i+d-1][j-1]+sum[2][i-1][j-1];
                int even1=sum[3][i+d-1][j+d-1]-sum[3][i-1][j+d-1]-sum[3][i+d-1][j-1]+sum[3][i-1][j-1];
                need[d]=min(need[d],odd-odd0+even-even1);
                need[d]=min(need[d],odd-odd1+even-even0);
            }
    scanf("%d",&Q);
    for(int i=0;i<Q;i++)
    {
        int x;scanf("%d",&x);
        for(int j=min(N,M);j>=1;j--)
            if(need[j]<=x) {printf("%d\n",j); break;}
    }
    return 0;
}

