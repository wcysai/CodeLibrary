#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
map<string,int> months;
int s,t,n;
int dp[MAXN][MAXM],choice[MAXN][MAXM];
int leap[MAXN];
int m1[MAXN],d1[MAXN],m2[MAXN],d2[MAXN],type[MAXN];
string mth[13];
string str;
void loadmonths()
{
    months["January"]=1; months["February"]=2; months["March"]=3;
    months["April"]=4; months["May"]=5; months["June"]=6;
    months["July"]=7; months["August"]=8; months["September"]=9;
    months["October"]=10; months["November"]=11; months["December"]=12;
    for(auto p:months) mth[p.S]=p.F;
}
bool isleapyear(int y)
{
    if(y%100!=0&&y%4==0) return true;
    if(y%400==0) return true;
    return false;
}
void findleapyears()
{
    for(int i=t-s;i>=0;i--)
    {
        leap[i]=leap[i+1];
        if(isleapyear(i+s)) leap[i]++;
    }
}
bool checklater(int y1,int m1,int d1,int y2,int m2,int d2)
{
    if(y2>y1) return true;
    if(y2==y1&&m2>m1) return true;
    if(y2==y1&&m2==m1&&d2>d1) return true;
    return false;
}
bool checkvalid(int y,int m,int d)
{
    if(y<s||y>t) return false;
    if(!isleapyear(y)&&m==2&&d==29) return false;
    return true;
}
int countdays(int y,int m,int d,int m2,int d2)
{
    if(m2==2&&d2==29)
    {
        if(checklater(y,m,d,y,m2,d2)) return leap[y];
        else return leap[y+1];
    }
    if(checklater(y,m,d,y,m2,d2)) return (t-s)-y+1;
    else return (t-s)-y;
}
void print(int y,int m1,int d1,int type,int m2,int d2)
{
    cout<<mth[m1]<<" "<<d1<<" "<<y<<", "<<(type==1?"added":"removed")<<" "<<mth[m2]<<" "<<d2<<endl;
}
void go(int y,int i)
{
    if(i>1) go(choice[i][y],i-1);
    print(s+y,m1[i-1],d1[i-1],type[i-1],m2[i-1],d2[i-1]); 
}
int main()
{
    freopen("holidays.in","r",stdin);
    freopen("holidays.out","w",stdout);
    loadmonths();
    scanf("%d%d%d ",&s,&t,&n);
    findleapyears();
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        cin>>str; m1[i]=months[str];
        scanf("%d, ",&d1[i]);
        cin>>str; type[i]=(str=="added"?1:-1);
        cin>>str; m2[i]=months[str];
        scanf("%d",&d2[i]);
        for(int j=0;j<=t-s;j++)
        {
            if(dp[i][j]==-1) continue;
            for(int k=j;k<=t-s;k++)
            {
                if(!checkvalid(k+s,m1[i],d1[i])) continue;
                if(i>0&&!checklater(j,m1[i-1],d1[i-1],k,m1[i],d1[i])) continue;
                if(dp[i][j]+type[i]*countdays(k,m1[i],d1[i],m2[i],d2[i])>dp[i+1][k])
                {
                    dp[i+1][k]=dp[i][j]+type[i]*countdays(k,m1[i],d1[i],m2[i],d2[i]);
                    choice[i+1][k]=j;
                }
            }
        }
    }
    int id=-1,ans=-1;
    for(int i=0;i<=t-s;i++) if(dp[n][i]>ans) {ans=dp[n][i]; id=i;}
    printf("%d\n",ans);
    if(ans!=-1) go(id,n);
    return 0;
}
