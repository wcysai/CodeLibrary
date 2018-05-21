#include<bits/stdc++.h>
#define MAXN 12
using namespace std;
struct trie
{
    trie *next[10];
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
int n;
bool insert(trie *s,char x[])
{
    int i;
    trie *t;
    bool f=true,ff=false;
    for(i=0; x[i] ; i++)
    {
        if( s->next[ x[i]-'0' ] ) { s=s->next[ x[i]-'0' ];}
        else
        {
            ff=true;
            t=newnode();
            s->next[ x[i]-'0' ]=t;
            s=t;
        }
        if(s->mark) f=false;
    }
    s->mark=true;
    if(!ff) f=false;
    return f;
}
void deltrie(trie *s)
{
    int i;
    for(i=0;i<10;i++)
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
    scanf("%d",&n);
    int m;
    char word[MAXN];
    for(int i=0;i<n;i++)
    {
        thead=newnode();
        bool flag=true;
       scanf("%d",&m);
       for(int j=0;j<m;j++)
       {
           scanf("%s",word);
         if(!insert(thead,word)) flag=false;
       }
       if(flag) printf("YES\n"); else printf("NO\n");
       deltrie(thead);
    }
    return 0;
}

