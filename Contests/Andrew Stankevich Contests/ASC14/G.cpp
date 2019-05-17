#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,tot;
string str;
int len[MAXN];
int trie[MAXN][26];
bool ed[MAXN];
int ans=0;
void insert(string s,int rt)
{
    for(int i=0;i<(int)s.size();i++)
    {
        int x=s[i]-'A';
        if(trie[rt][x]==0) trie[rt][x]=++tot;
        rt=trie[rt][x];
        if(!ed[rt]) ans++;
        ed[rt]=true;
    }
}
void clear()
{
    memset(trie,0,sizeof(trie)); memset(ed,0,sizeof(ed)); tot=0;
}
int main()
{
    freopen("palindromes.in","r",stdin);
    freopen("palindromes.out","w",stdout);
    cin>>str;
    n=str.size();
    len[0]=1;
    for(int i=1,j=0;i<(n<<1)-1;i++)
    {
        int p=i>>1,q=i-p,r=((j+1)>>1)+len[j]-1;
        len[i]=r<q?0:min(r-q+1,len[(j<<1)-i]);
        while(p>len[i]-1&&q+len[i]<n&&str[p-len[i]]==str[q+len[i]]) ++len[i];
        if(q+len[i]-1>r) j=i;
    }
    clear();
    for(int i=0;i<2*n-1;i+=2)
    {
        if(!len[i]) continue;
        string s=str.substr(i/2-len[i]+1,len[i]); reverse(s.begin(),s.end());
        insert(s,0);
    }
    clear();
    for(int i=1;i<2*n-1;i+=2)
    {
        if(!len[i]) continue;
        string s=str.substr(i/2-len[i]+1,len[i]); reverse(s.begin(),s.end());
        insert(s,0);
    }
    printf("%d\n",ans);
    return 0;
}
