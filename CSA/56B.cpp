#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
int t,c,n;
int x[MAXN],y[MAXN],s[MAXN];
int main()
{
    scanf("%d%d%d",&t,&c,&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d",&x[i],&y[i],&s[i]);
    for(int i=0;i<t;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
            if(x[j]*s[j]+i*c*s[j]==y[j]*c) cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}

