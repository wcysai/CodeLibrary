#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 10000
#define INF 1000000000
using namespace std;
int n,k;
double len[MAXN];
bool C(double x)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=(int)(len[i]/x);
    if(sum>=k) return true; else return false;
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%lf",&len[i]);
    double left=0,right=INF;
    for(int i=0;i<100;i++)
    {
        double mid=(left+right)/2;
        if(C(mid)) left=mid;
        else right=mid;
    }
    printf("%.2lf\n",floor(right*100)/100);
    return 0;
}