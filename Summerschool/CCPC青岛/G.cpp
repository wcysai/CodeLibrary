#include<bits/stdc++.h>
#define MAXN 300
#define INF 200000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
char str[MAXN];
int dp[MAXN][MAXN];
int query;
vector<P> save;
int main()
{
    scanf("%d",&query);
    int q=0;
    while(query--)
    {
        for(int i=0;i<MAXN;i++)
            for(int j=0;j<MAXN;j++)
                dp[i][j]=INF;
        q++;
        save.clear();
        scanf("%s",str);
        int x=strlen(str);
        int k=0,t=(int)str[0]-48,cnt=0;
        while(k<x)
        {
            int p=(int) str[k]-48;
            if(p==t) cnt++;
            else
            {
                save.push_back(P(t,cnt));
                t=p;
                cnt=1;
            }
            k++;
        }
        save.push_back(P(t,cnt));
        int len=save.size();
        for(int i=0;i<len;i++)
            dp[i][i]=save[i].second==1?2:1;
        for(int l=2;l<=len;l++)
        {
            for(int i=0;i<len+1-l;i++)
            {
                int j=i+l-1;
                for(int it=i;it<j;it++)
                    dp[i][j]=min(dp[i][j],dp[i][it]+dp[it+1][j]);
                if(save[i].first==save[j].first)
                {
                    dp[i][j]=min(dp[i][j],dp[i+1][j-1]+(save[i].second+save[j].second==2?1:0));
                    if(save[i].second==1||save[j].second==1)
                    {
                        for(int it=i+1;it<j;it++)
                            if(save[it].first==save[i].first&&save[it].second==1)
                                dp[i][j]=min(dp[i][j],dp[i+1][it-1]+dp[it+1][j-1]);
                    }
                }
            }
        }
        printf("Case #%d: %d\n",q,dp[0][len-1]);
    }
    return 0;
}
