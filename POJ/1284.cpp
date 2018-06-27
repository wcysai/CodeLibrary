#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#define MAXN 65536
using namespace std;
typedef long long ll;
int phi[MAXN];
void phi2()
{
    for(int i=0;i<MAXN;i++) phi[i]=i;
    for(int i=2;i<MAXN;i++)
        if(phi[i]==i)
            for(int j=i;j<MAXN;j+=i) phi[j]=phi[j]/i*(i-1);
}
int main()
{
    phi2();
    int n;
    while(scanf("%d",&n)==1)
        printf("%d\n",phi[n-1]);
    return 0;
}
