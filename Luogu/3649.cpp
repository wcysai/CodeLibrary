#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string s;
struct PAM{
    int s[MAXN],now;
    int nxt[MAXN][26],fail[MAXN],l[MAXN],cnt[MAXN],last,tot;
    vector<int> G[MAXN];
    void clear(){
        //1节点：奇数长度root 0节点：偶数长度root
        s[0]=l[1]=-1;
        fail[0] = tot = now =1;
        last = l[0]=0;
        memset(nxt[0],0,sizeof(nxt[0]));
        memset(nxt[1],0,sizeof(nxt[1]));
    }
    PAM(){clear();}
    int newnode(int len){
        tot++;
        memset(nxt[tot],0,sizeof nxt[tot]);
        fail[tot]=0;
        l[tot]=len;
        return tot;
    }
    int get_fail(int x){
        while (s[now-l[x]-2]!=s[now-1])x = fail[x];
        return x;
    }
    void add(int ch){
        s[now++] = ch;
        int cur = get_fail(last);
        if(!nxt[cur][ch]){
            int tt = newnode(l[cur]+2);
            fail[tt] = nxt[get_fail(fail[cur])][ch];
            nxt[cur][ch] = tt;
        }
        last = nxt[cur][ch];
        cnt[last]++;
    }
    void dfs(int v)
    {
        for(auto to:G[v])
        {
            dfs(to);
            cnt[v]+=cnt[to];
        }
    }
    int init(string s){
        int n = s.size();
        for (int i=0;i<n;i++)
            add(s[i] - 'a');
        for(int i=1;i<=tot;i++) G[fail[i]].push_back(i);
        dfs(0);
        int ans=0;
        for(int i=2;i<=tot;i++) ans=max(ans,cnt[i]*(l[i]));
        return ans;
    }
}pam;
int main()
{
    cin>>s;
    cout<<pam.init(s)<<endl;
    return 0;
}
