#include<bits/stdc++.h>
#define MAXN 500005
using namespace std;
typedef long long ll;
struct PAM{
    int s[MAXN],now,ans;
    int nxt[MAXN][26],fail[MAXN],l[MAXN],occ[MAXN],last,tot;
    int cnt[2*MAXN];
    vector<int> G[MAXN];
    void clear(){ //1: odd root 0: even root
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
        occ[last]++;
    }
    void dfs(int v)
    {
        if(l[v]%4==0&&cnt[l[v]]) ans=max(ans,l[v]);
        cnt[2*l[v]]++;
        for(auto to:G[v]) dfs(to);
        cnt[2*l[v]]--;
    }
    ll init(string str){
        for (int i=0;i<(int)str.size();i++) add(str[i] - 'a');
        ans=0;
        for(int i=2;i<=tot;i++) G[fail[i]].push_back(i);
        dfs(0);
        return ans;
    }
}pam;
int n;
string str;
int main()
{
    cin>>n>>str;
    cout<<pam.init(str)<<endl;
    return 0;
}

