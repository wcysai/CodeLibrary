
#include<bits/stdc++.h>
#define MAXN 50020
using namespace std;
struct trie
{
    trie *next[2];
    bool mark;
};
trie *thead;
inline trie * newnode()
{
    int i;
    trie *t;
    t=(trie*)malloc(sizeof(trie));
    memset(t,0,sizeof(trie));
    t->mark=false;
    return t;
}
bool insert(trie *s,char x[])
{
    int i;
    trie *t;
    bool f=true;
    for(i=0; x[i] ; i++)
    {
        if( s->next[ x[i]-'0' ] ) { s=s->next[ x[i]-'0' ];}
        else
        {
            t=newnode();
            s->next[ x[i]-'0' ]=t;
            s=t;
        }
        if(s->mark) f=false;
    }
    s->mark=true;
    return f;
}
void deltrie(trie *s)
{
    int i;
    for(i=0; i < 2 ;i++)
    {
        if( s->next[i] )
        deltrie(s->next[i]);
    }
    free(s);
    s=NULL;
}
bool find(char x[])
{
    trie *s=thead;
    int i;
    for(i=0; x[i] ; i++)
    {
        if( s->next[ x[i]-'0' ]==NULL ) return false;
        s=s->next[ x[i]-'0' ];
    }
    return true;
}
int main()
{
    int i=1;
    thead=newnode();
    char word[10];
    bool flag=true;
    while(scanf("%s",word)==1)
    {
        if(word[0]=='9')
        {
             if(flag) printf("Set %d is immediately decodable\n",i); else printf("Set %d is not immediately decodable\n",i);
             i++;
             deltrie(thead);
             thead=newnode();
             flag=true;
        }
        else if(!insert(thead,word)) flag=false;
    }
    return 0;
}
