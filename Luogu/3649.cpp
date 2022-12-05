#include<bits/stdc++.h>
#define MAXN 300005
using namespace std;
typedef long long ll;
struct PAM{
    int s[MAXN],now;
    int nxt[MAXN][26],fail[MAXN],l[MAXN],occ[MAXN],last,tot;
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
    ll init(string str){
        for (int i=0;i<(int)str.size();i++) add(str[i] - 'a');
        ll ans=0;
        for(int i=tot;i>=1;i--) {occ[fail[i]]+=occ[i]; ans=max(ans,1LL*occ[i]*l[i]);}
        return ans;
    }
}pam;
string str;
int main()
{
    cin>>str;
    pam.clear();
    cout<<pam.init(str)<<endl;
    return 0;
}

