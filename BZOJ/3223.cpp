#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int ch[MAXN][2],f[MAXN],size[MAXN],cnt[MAXN],key[MAXN],rev[MAXN];
int n,m,sz,root,tot;
inline bool get(int x)
{
    return ch[f[x]][1]==x;
}
inline void pushup(int x)
{
    size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
}
inline void pushdown(int x)
{
    if(!rev[x]) return;
    int lson=ch[x][0],rson=ch[x][1];
    swap(ch[lson][0],ch[lson][1]);swap(ch[rson][0],ch[rson][1]);
    rev[lson]^=1;rev[rson]^=1;
    rev[x]=0;
}
inline void rotate(int x)
{
    int old=f[x],oldf=f[old],whichx=get(x);
    ch[old][whichx]=ch[x][whichx^1]; f[ch[old][whichx]]=old;
    ch[x][whichx^1]=old; f[old]=x;
    f[x]=oldf;
    if (oldf) ch[oldf][ch[oldf][1]==old]=x;
    pushup(old); pushup(x);
}
inline void splay(int x,int goal)
{
    for(int fa;(fa=f[x])!=goal;rotate(x))
        if(f[fa]!=goal) rotate((get(x)==get(fa))?fa:x);
    if(goal==0) root=x;
}
inline int findx(int x,int k)
{
    while(x)
    {
        pushdown(x);
        int ss=size[ch[x][0]]+1;
        if(k==ss) return x;
        if(k>ss) x=ch[x][1],k-=ss;
        else x=ch[x][0];
    }
}
void build(int &k,int l,int r,int fa)
{
    if(l>r) return;
    int mid=(l+r)/2;
    k=++tot;f[k]=fa;
    key[k]=mid;size[k]=1;
    build(ch[k][0],l,mid-1,k);build(ch[k][1],mid+1,r,k);
    pushup(k);
}
void print(int x)
{
    if(!x) return;
    pushdown(x);
    print(ch[x][0]);
    if(key[x]!=0&&key[x]!=n+1) printf("%d ",key[x]);
    print(ch[x][1]);
}
void reverse(int l,int r)
{
    int x=findx(root,l-1);splay(x,0); 
    int y=findx(root,r+1);splay(y,root); 
    int t=ch[y][0];swap(ch[t][0],ch[t][1]);rev[t]^=1;
}
int main()
{
    scanf("%d%d",&n,&m);
    build(root,0,n+1,0);
    int l,r;
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&l,&r);l++;r++;
        reverse(l,r);
    }
    print(root);printf("\n");
}


