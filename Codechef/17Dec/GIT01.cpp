#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 105
#define INF 1000000000
using namespace std;
int n,m,t;
char str[MAXN][MAXM];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        int ans=INF,cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {zAZ
                if(str[i][j]=='R'&&((i+j)%2==0)) cnt+=5;
                if(str[i][j]=='G'&&((i+j)%2==1)) cnt+=3;
            }
        ans=min(ans,cnt);
        cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='G'&&((i+j)%2==0)) cnt+=3;
                if(str[i][j]=='R'&&((i+j)%2==1)) cnt+=5;
            }
        ans=min(ans,cnt);
        printf("%d\n",ans);
    }
    return 0;
}
