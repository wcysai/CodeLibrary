#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct trie
{
    trie *next[26];
    int pre;
};
trie *thead;
char
inline trie * newnode()
{
    int i;
    trie *t;
    t=(trie*)malloc(sizeof(trie));
    memset(t,0,sizeof(trie));
    return t;
}
void insert(trie *s,char x[])
{
    int i;
    trie *t;
    s->pre++;
    for(i=0; x[i] ; i++)
    {
        if( s->next[ x[i]-'a' ] ) { s=s->next[ x[i]-'a' ]; s->pre++;}
        else
        {
            t=newnode();
            s->next[ x[i]-'a' ]=t;
            s=t;
            s->pre++;
        }
    }
}
void deltrie(trie * s)
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
int find(trie *s, char x[])
{
    int i;
    if(x[0] == 0) return -1;
    for(i=0; x[i] ; i++)
    {
        if( s->next[ x[i]-'a' ] ) s=s->next[ x[i]-'a' ];
        else break;
    }
    if(x[i]==0) return s->pre;
    else return 0;
}
int main()
{
    char word[10];
    thead=newnode();
    while(gets(word))
    {
        int x=strlen(word);
        if(x==0) break;
        insert(thead,word);
    }
    while(scanf("%s",word)==1)
    {
       printf("%d\n",find(thead,word));
    }
    deltrie(thead);
    return 0;
}

