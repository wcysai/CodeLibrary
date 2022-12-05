#include<bits/stdc++.h>
#define MAXN 1000005
#define F first
#define S second
#define MOD 1000000007
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
void madd(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
struct PAM{
    int s[MAXN],now;
    int nxt[MAXN][26],fail[MAXN],l[MAXN],last,tot;
    int diff[MAXN],anc[MAXN];//anc: into the nxt A.P.
    int dp[MAXN],f[MAXN];
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
            diff[tt]=l[tt]-l[fail[tt]];
            anc[tt]=diff[tt]==diff[fail[tt]]?anc[fail[tt]]:fail[tt];
        }
        last = nxt[cur][ch];
    }
    void update(int i){
        for(int p=last;p>1;p=anc[p])
        {
            f[p]=dp[i-l[anc[p]]-diff[p]];
            if(diff[p]==diff[fail[p]]) madd(f[p],f[fail[p]]);
            if(i%2==0) madd(dp[i],f[p]);
        }
    }
    int init(string str){
        int n=(int)str.size();
        dp[0]=1;
        for (int i=0;i<n;i++) 
        {
            add(str[i] - 'a');
            update(i+1);
        }
        return dp[n];
    }
}pam;
string str,t;
int main()
{
    cin>>str;
    t="";
    int n=(int)str.size();
    for(int i=0;i<n/2;i++)
    {
        t+=str[i];
        t+=str[n-1-i];
    }
    cout<<pam.init(t)<<endl;
    return 0;
}

