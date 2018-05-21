#include<bits/stdc++.h>
#define MAXN 3020
using namespace std;
char a[MAXN],c[MAXN];
pair<char,bool> b[MAXN];
bool dp[MAXN][MAXN];
bool judge(char x,char y)
{
    if(x=='.') return true;
    else return x==y?true:false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        scanf("%s",c);
        int x=strlen(a),y=strlen(c);
        int k1=0,k2=0;
        while(k1<y)
        {
            if(k1==y-1||c[k1+1]!='*')
            {
                b[k2].first=c[k1];
                b[k2].second=false;
                k1++;
                k2++;
            }
            else
            {
                b[k2].first=c[k1];
                b[k2].second=true;
                k1+=2;
                k2++;
            }
        }
        if(!b[0].second)
        {
            dp[0][0]=false;
            for(int i=1;i<=x;i++)
                if(i==1&&judge(b[0].first,a[i-1])) dp[0][i]=true; else dp[0][i]=false;
        }
        else
        {
            dp[0][0]=true;
            for(int i=1;i<=x;i++)
                if((i==1&&judge(b[0].first,a[i-1]))||(i!=1&&dp[0][i-1]&&a[i-1]==a[i-2])) dp[0][i]=true; else dp[0][i]=false;
        }
        for(int i=1;i<k2;i++)
        {
             if(!b[i].second)
             {
                 dp[i][0]=false;
                for(int j=1;j<=x;j++)
                    if(dp[i-1][j-1]&&judge(b[i].first,a[j-1])) dp[i][j]=true; else dp[i][j]=false;

            }
            else
            {
                dp[i][0]=dp[i-1][0];
                for(int j=1;j<=x;j++)
                {
                    if(dp[i-1][j]) dp[i][j]=true;
                    else
                    {
                        if (dp[i][j-1]&&judge(b[i].first,a[j-1])) {dp[i][j]=true; b[i].first=a[j-1];} else dp[i][j]=false;
                    }

            }
        }
        }
        printf(dp[k2-1][x]?"yes\n":"no\n");
    }
    return 0;
}
