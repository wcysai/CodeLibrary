#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
int dp[MAXN][6][5];
vector<int> choice[MAXN][6][5];
int string_to_int(string str)
{
    int s=0;
    for(int i=0;i<(int)str.size();i++) s=s*10+str[i]-'0';
    return s;
}
P save[MAXN][6][5];
vector<string> v[MAXN][5];
vector<string> lans;
int main()
{
    freopen("dvd.in","r",stdin);
    freopen("dvd.out","w",stdout);
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        getline(cin,str);
        int cnt=0;
        for(int i=0;i<(int)str.size();i++)
        {
            if(str[i]=='\"') cnt++;
            if(cnt==2)
            {
                string name=str.substr(0,i+1);
                int region=string_to_int(str.substr(i+7,1))-1;
                int year=string_to_int(str.substr(i+2,4))-1870;
                v[year][region].push_back(name);
                break;
            }
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<6;j++)
            for(int k=0;k<5;k++)
                dp[i][j][k]=-INF;
    for(int i=0;i<5;i++) dp[0][0][i]=0;
    for(int i=0;i<135;i++)
    {
        for(int j=0;j<6;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(dp[i][j][k]==-INF) continue;
                //printf("%d %d %d %d\n",i,j,k,dp[i][j][k]);
                for(int moves=0;moves<=min(4,5-j);moves++)
                {
                    for(int lastpos=0;lastpos<5;lastpos++)
                    {
                        if(moves==0&&lastpos!=k) continue;
                        if(moves!=0&&lastpos==k) continue;
                        int cnt=(moves==0?(int)v[i][k].size():(int)v[i][k].size()+(int)v[i][lastpos].size());
                        vector<P> vv; vv.clear();
                        for(int kk=0;kk<5;kk++) 
                        {
                            if(kk==k) continue;
                            if(kk==lastpos) continue;
                            vv.push_back(P((int)v[i][kk].size(),kk));
                        }
                        
                        sort(vv.begin(),vv.end(),greater<P>());
                        for(int kk=0;kk<=(moves==0?moves-1:moves-2);kk++) cnt+=(int)vv[kk].F;
                        if(dp[i+1][j+moves][lastpos]<dp[i][j][k]+cnt)
                        {
                            dp[i+1][j+moves][lastpos]=dp[i][j][k]+cnt;
                            save[i+1][j+moves][lastpos]=P(j,k);
                            choice[i+1][j+moves][lastpos].clear();
                            if(moves==0) choice[i+1][j+moves][lastpos].push_back(k); 
                            else 
                            {
                                choice[i+1][j+moves][lastpos].push_back(lastpos);
                                for(int kk=0;kk<=moves-2;kk++) 
                                {
                                    choice[i+1][j+moves][lastpos].push_back(vv[kk].S);
                                }
                                assert(k!=lastpos);
                                choice[i+1][j+moves][lastpos].push_back(k);
                            }
                        }
                    }
                }
            }
        }
    }
    int ans=0,x=-1,y=-1;
    for(int i=0;i<6;i++)
        for(int j=0;j<5;j++)
        {
            if(dp[135][i][j]>ans)
            {
                ans=dp[135][i][j];
                x=i;
                y=j;
            }
        }
    printf("%d\n",ans);
    int now=135;
    while(now>0)
    {
        int lastx=save[now][x][y].F,lasty=save[now][x][y].S;
        for(auto i:choice[now][x][y])
            for(int j=(int)v[now-1][i].size()-1;j>=0;j--)
                lans.push_back(v[now-1][i][j]);
        x=lastx,y=lasty;
        now--;
    }
    reverse(lans.begin(),lans.end());
    for(auto str:lans) cout<<str<<endl;
    return 0;
}
