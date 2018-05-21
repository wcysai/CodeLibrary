#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 100005
#define INF 1000000000
using namespace std;
int n,m;
int money[MAXN];
bool C(int p)
{
    int t=m-1;
    int crt=0;
    int sum=0;
    while(t>=0)
    {
        if(sum+money[crt]<=p)
        {
            sum+=money[crt];
            crt++;
        }
        else
        {
            if(money[crt]>p) return false;
            t--;
            sum=0;
        }
        if(t<0)  return false;
        if(crt>=n) return true;
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&money[i]);
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