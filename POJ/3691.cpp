#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<assert.h>
#include<queue>
#include<stack>
#include<deque>
#define MAXS 1005
#define MAXN 1005
#define INF 1000000000
using namespace std;
struct trie
{
    trie* next[26];
    trie* fail;
    trie* ban;
    int id;
    bool mark;
};
trie* thead;
vector<trie*> num;
char str[MAXN];
int dp[MAXN][MAXS];
int nxt[MAXS][4];
int ti=0,n;
char ATCG[4]={'A','T','C','G'};
inline trie*  newnode()
{
    trie* t;
    t=(trie*)malloc(sizeof(trie));
    t->fail=NULL;
    t->ban=NULL;
    t->mark=false;
    t->id=0;
    memset(t,0,sizeof(trie));
    return t;
}
void insert(char x[])
{
    int i;
    trie* s=thead;
    trie* t;
    for(i=0;x[i];i++)
    {
        if(s->next[x[i]-'A']) {s=s->next[x[i]-'A'];}
        else
        {
            t=newnode();
            s->next[x[i]-'A']=t;
            s=t;
            s->id=ti++;
            num.push_back(s);
        }
    }
    s->mark=true;
    return;
}
trie* g(trie* s, char x)
{
    if(s->next[x-'A']) return s->next[x-'A'];
    else if(s==thead) return thead;
    else return NULL;
}

void bfs()
{
    trie* s=thead;
    queue<trie*> que;
    for(int i=0;i<26;i++)
        if(s->next[i]){s->next[i]->fail=thead; que.push(s->next[i]);}
    while(!que.empty())
    {
        trie* t=que.front();
        que.pop();
        for(int i=0;i<26;i++)
            if(g(t,(char)('A'+i))!=NULL)
            {
                que.push(t->next[i]);
                trie* v=t->fail;
                while(g(v,(char)('A'+i))==NULL) v=v->fail;
                t->next[i]->fail=g(v,(char)('A'+i));
                if(t->next[i]->fail&&t->next[i]->fail->mark) t->next[i]->mark=true;
            }
    }
    return;
}
void deltrie(trie* s)
{
    int i;
    for(i=0;i<26;i++)
    {
        if(s->next[i])
        deltrie(s->next[i]);
    }
    free(s);
    s=NULL;
}
int main()
{
    int cnt=0;
    while(scanf("%d",&n)==1)
    {
        if(n==0) break;
        thead=newnode();
        num.clear();
        num.push_back(thead);
        thead->id=0;
        ti=1;
        for(int i=0;i<n;i++)
        {
            scanf("%s",str);
            insert(str);
        }
        bfs();
        for(int i=0;i<ti;i++)
        {
            for(int j=0;j<4;j++)
            {
                trie* pt=num[i];
                while(g(pt,ATCG[j])==NULL)
                    pt=pt->fail;
                pt=g(pt,ATCG[j]);
                nxt[i][j]=pt->id;
            }
        }
        scanf("%s",str);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<ti;j++)
                dp[i+1][j]=INF;
            for(int j=0;j<ti;j++)
            {
                if(num[j]->mark) continue;
                for(int k=0;k<4;k++)
                {
                    int to=nxt[j][k];
                    dp[i+1][to]=min(dp[i+1][to],dp[i][j]+(str[i]==ATCG[k]?0:1));
                }
            }
        }
        int ans=INF;
        for(int i=0;i<ti;i++)
        {
            if(num[i]->mark) continue;
            ans=min(ans,dp[len][i]);
        }
        printf("Case %d: ",++cnt);
        if(ans==INF) puts("-1");
        else printf("%d\n",ans);
        deltrie(thead);
    }
    return 0;
}
