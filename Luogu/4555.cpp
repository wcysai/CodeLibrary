#include<bits/stdc++.h>
#define MAXN 300005
using namespace std;
typedef long long ll;
struct PAM{
    int s[MAXN],now,id;
    int nxt[MAXN][26],fail[MAXN],l[MAXN],save[2][MAXN],last,tot;
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
        save[id][now-1]=l[last];
    }
    void init(string str,int x){
        now=1; last=0; id=x;
        for (int i=0;i<(int)str.size();i++) add(str[i] - 'a');
    }
}pam;
string str;
int main()
{
    cin>>str;
    int n=(int)str.size();
    pam.init(str,0);
    reverse(str.begin(),str.end());
    pam.init(str,1);
    int ans=0;
    for(int i=1;i<=n-1;i++) 
        if(pam.save[0][i]&&pam.save[1][n-i]) ans=max(ans,pam.save[0][i]+pam.save[1][n-i]); 
    cout<<ans<<endl;
    return 0;
}

