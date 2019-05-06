#include<bits/stdc++.h>
#define MAXN 35
#define MAXW 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k,w;
char mp[MAXN][MAXN];
int letter[MAXN][MAXN],word[MAXN][MAXN];
char str[MAXN];
char words[MAXW][MAXN];
int v[30],ans;
int type,xx,yy,ww;
vector<int> has;
int chas[30],ccnt[30];
void check_vertical(int x,int y,int id)
{
    memset(ccnt,0,sizeof(ccnt));
    for(auto x:has) ccnt[x]=chas[x];
    int l=strlen(words[id]+1);
    if(x+l-1>n) return;
    if(x>1&&mp[x-1][y]!='.') return;
    if(x+l-1<n&&mp[x+l][y]!='.') return;
    int val=0,mult=1,cc=0;
    for(int i=x;i<=x+l-1;i++)
    {
        int pos=i-x+1;
        int let=words[id][pos]-'A';
        if(mp[i][y]=='.')
        {
            cc++;
            if(y>1&&mp[i][y-1]!='.') return;
            if(y<m&&mp[i][y+1]!='.') return;
            if(!ccnt[let]) return;
            ccnt[let]--;
        }
        else if(mp[i][y]-'A'!=let) return;
        val+=letter[i][y]*v[let];
        mult*=word[i][y];
    }
    if(cc==0||cc==l) return;
    ans=max(ans,mult*val);
}
void check_horizontal(int x,int y,int id)
{
    memset(ccnt,0,sizeof(ccnt));
    for(auto x:has) ccnt[x]=chas[x];
    int l=strlen(words[id]+1);
    if(y+l-1>m) return;
    if(y>1&&mp[x][y-1]!='.') return;
    if(y+l-1<m&&mp[x][y+l]!='.') return;
    int val=0,mult=1,cc=0;
    for(int i=y;i<=y+l-1;i++)
    {
        int pos=i-y+1;
        int let=words[id][pos]-'A';
        if(mp[x][i]=='.')
        {
            cc++;
            if(x>1&&mp[x-1][i]!='.') return;
            if(x<n&&mp[x+1][i]!='.') return;
            if(!ccnt[let]) return;
            ccnt[let]--;
        }
        else if(mp[x][i]-'A'!=let) return;
        val+=letter[x][i]*v[let];
        mult*=word[x][i];
    }
    if(cc==0||cc==l) return; 
    ans=max(ans,mult*val);
}
int main()
{
    freopen("words.in","r",stdin);
    freopen("words.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) letter[i][j]=word[i][j]=1;
    int b,t;
    scanf("%d",&b);
    for(int i=0;i<b;i++)
    {
        scanf("%s",str);
        int coef,cnt;
        scanf("%d",&coef);
        scanf("%d",&cnt);
        for(int j=0;j<cnt;j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            assert(1<=x&&x<=n); assert(1<=y&&y<=m);
            if(str[0]=='L') letter[x][y]=coef; else word[x][y]=coef;
        }
    }
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%s",str);
        int val,len;
        scanf("%d",&val);
        len=strlen(str);
        for(int j=0;j<len;j++) v[str[j]-'A']=val;
    }
    for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
    scanf("%d",&k);
    scanf("%s",str);
    for(int i=0;i<k;i++) has.push_back((int)str[i]-'A');
    for(auto x:has) chas[x]++;
    scanf("%d",&w);
    for(int i=1;i<=w;i++) scanf("%s",words[i]+1);
    ans=0;
    for(int i=1;i<=w;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
            {
                check_vertical(j,k,i);
                check_horizontal(j,k,i);
            }
    printf("%d\n",ans);
    return 0;
}
