#include<bits/stdc++.h>
#define MAXN 600005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,tot=0,ans;
string str[MAXN];
int trie[MAXN][26],cnt[MAXN];
void ins(string &s)
{
    int rt=0;
    cnt[rt]++;
    for(int i=0;i<(int)s.size();i++)
    {
        int x=s[i]-'a';
        if(trie[rt][x]==0) trie[rt][x]=++tot;
        else ans=max(ans,i+1);
        rt=trie[rt][x];
        cnt[rt]++;
    }
}
int qry(string &s){
    int rt=0,ans=0;
    for(int i=0;i<(int)s.size();i++)
    {
        int x=s[i]-'a';
        rt=trie[rt][x];
        if(cnt[rt]>=2) ans=max(ans,i+1);
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>str[i];
        ins(str[i]);
    }
    for(int i=0;i<n;i++) printf("%d\n",qry(str[i]));
    return 0;
}


