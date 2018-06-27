#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,r,k;
int main()
{
    scanf("%d%d%d",&n,&r,&k);
    printf("%d %d\n",r-k<=0?k-r:r-k,r+k>=n?n-(r+k-n):r+k);
    return 0;
}

