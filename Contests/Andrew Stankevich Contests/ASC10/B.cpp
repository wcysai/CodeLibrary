#include<bits/stdc++.h>
#define MAXN 10005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int t,m,n,d,h,z,c;
int regionfa[MAXN],townfa[MAXN];
string regioncode[MAXN];
set<int> covered;
string str;
int w[5][5];
int tot=1,root=1;
int trie[MAXM][10],cnt[MAXM];
P ed[MAXM];
void insert(string s,int rt,P p)
{
    for(int i=0;i<(int)s.size();i++)
    {
        int x=s[i]-'0';
        if(trie[rt][x]==0) trie[rt][x]=++tot;
        rt=trie[rt][x];
        cnt[rt]++;
    }
    ed[rt]=p;
}
P find(string s,int rt)
{
    for(int i=0;i<(int)s.size();i++)
    {
        int x=s[i]-'0';
        if(trie[rt][x]==0) return P(-1,-1);
        rt=trie[rt][x];
        if(cnt[rt]==1&&ed[rt].F) return ed[rt];
    }
    return P(-1,-1);
}
int main()
{
    freopen("called.in","r",stdin);
    freopen("called.out","w",stdout);
    scanf("%d%d%d%d",&t,&m,&n,&d);
    for(int i=1;i<=m;i++)
    {
        scanf("%intd",&regionfa[i]);
        cin>>regioncode[i];
    }
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&townfa[i]);
        int x; scanf("%id",&x);
        if(x==0)
        {
            str=regioncode[townfa[i]];
            insert(str,root,P(townfa[i],i));
        }
        for(int j=0;j<x;j++)
        {
            cin>>str;
            str=regioncode[townfa[i]]+str;
            insert(str,root,P(townfa[i],i));
        }
    }
    scanf("%d%d",&h,&z);
    for(int i=1;i<=z;i++)
    {
        int x;scanf("%d",&x);
        covered.insert(x);
    }
    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            scanf("%d",&w[i][j]);
    long long ans=0;
    scanf("%d",&c);
    for(int i=0;i<c;i++)
    {
        int x,y;
        scanf("%intd",&x);
        string str;
        cin>>str;
        scanf("%intd",&y);
        P p=find(str,root);
        if(p.F==-1) continue;
        int reg=p.F,tw=p.S; 
        int type1,type2;
        if(!covered.count(townfa[x])) type1=4;
        else if(townfa[x]==h) type1=1;
        else if(regionfa[townfa[x]]==regionfa[h]) type1=2;
        else if(covered.count(townfa[x])) type1=3;
        else type1=4;
        if(tw==-1) type2=4;
        else if(tw==x||(tw==0&&townfa[x]==reg)) type2=1;
        else if(reg==townfa[x]) type2=2;
        else if(covered.count(reg)) type2=3;
        else type2=4;
        //printf("%intd %intd %intd %intd %intd\n",i,reg,tw,type1,type2);
        ans+=1LL*w[type1][type2]*y;
    }
    printf("%lld\n",ans);
    return 0;
}
