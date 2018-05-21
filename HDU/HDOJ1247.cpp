#include<bits/stdc++.h>
#define MAXN 50020
using namespace std;
struct trie
{
    trie *next[26];
    bool mark;
};
trie *thead;
char str[MAXN][1001];
inline trie * newnode()
{
    int i;
    trie *t;
    t=(trie*)malloc(sizeof(trie));
    memset(t,0,sizeof(trie));
    t->mark=false;
    return t;
}
void insert(trie *s,char x[])
{
    int i;
    trie *t;
    for(i=0; x[i] ; i++)
    {
        if( s->next[ x[i]-'a' ] ) { s=s->next[ x[i]-'a' ];}
        else
        {
            t=newnode();
            s->next[ x[i]-'a' ]=t;
            s=t;
        }
    }
    s->mark=true;
}
void deltrie(trie *s)
{
    int i;
    for(i=0; i < 26 ;i++)
    {
        if( s->next[i] )
        deltrie(s->next[i]);
    }
    free(s);
    s=NULL;
}
int find(char x[],bool f)
{
    int i;
    trie *s=thead;
    for(i=0;x[i];i++)
    {
        if(s->next[x[i]-'a']==NULL) return 0;
        s=s->next[x[i]-'a'];
        if(s->mark&&f)
        {
            char tt[1001];
            int j;
            for(j=i+1;x[j];j++)
                tt[j-(i+1)]=x[j];
             tt[j-(i+1)]='\0';
             if(find(tt,false)==1)
                return 2;
        }
    }
    if(s->mark) return 1;
    else return 0;
}
int main()
{
    int i=0;
    thead=newnode();
    while(scanf("%s",str[i])==1)
    {
        insert(thead,str[i]);
        i++;
    }
    for(int j=0;j<i;j++)
        if(find(str[j],true)==2)
            printf("%s\n",str[j]);
    deltrie(thead);
    return 0;
}
