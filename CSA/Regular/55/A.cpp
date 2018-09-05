#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,m;
int a[MAXN],b[MAXN][2];
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d%d",&b[i][0],&b[i][1]);
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for(int j=0;j<m;j++)
            if(a[j]>=b[i][0]&&a[j]<=b[i][1]) cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
