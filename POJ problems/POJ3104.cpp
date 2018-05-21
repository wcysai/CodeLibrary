#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 100005
#define INF 1000000000
using namespace std;
int n,k;
int dry[MAXN];
bool C(int x)
{
    long long sum=0;
    for(int i=0;i<n;i++)
        if(dry[i]-x>0)
        {
            if(k==1) return false;
            else sum+=(dry[i]-x-1)/(k-1)+1;
        }
    if(sum<=x) return true; else return false;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&dry[i]);
    scanf("%d",&k);
    int left=0,right=INF;
    while(right-left>1)
    {
        int mid=(left+right)/2;
        if(C(mid)) right=mid;
        else left=mid;
    }
    printf("%d\n",right);
    return 0;
}
