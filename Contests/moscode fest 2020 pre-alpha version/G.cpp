#include<bits/stdc++.h>
#define MAXN 600005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int dir[40],undir[40];
int main()
{
    dir[0]=undir[0]=1;
    dir[1]=2; undir[1]=1;
    dir[2]=2; undir[2]=2;
    for(int i=3;i<=30;i++)
    {
        undir[i]=i;
        for(int j=2;j<=i;j++)
        {
            undir[i]=max(undir[i],undir[j]*undir[i-j]);
            dir[i]=max(dir[i],undir[j]*dir[i-j]);
        }
        printf("%d %d %d\n",i,dir[i],undir[i]);
    }
    printf("%d\n",dir[20]);
    return 0;
}