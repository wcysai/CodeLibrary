#include<bits/stdc++.h>
#define MAXN 1000005
#define MOD 19930726
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
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
    int init(string str,ll k){
        for (int i=0;i<(int)str.size();i++) add(str[i] - 'a');
        int ans=1;
        vector<P> v;
        for(int i=tot;i>=2;i--) occ[fail[i]]+=occ[i];
        for(int i=2;i<=tot;i++) if(l[i]&1) v.push_back(P(l[i],occ[i]));
        sort(v.begin(),v.end(),greater<P>());
        for(int i=0;i<(int)v.size();i++) 
        {
            if(!k) break;
            ll need=min(k,1LL*v[i].S);
            ans=1LL*ans*pow_mod(v[i].F,need)%MOD;
            k-=need;
        }
        if(k) return -1;
        return ans;
    }
}pam;
string str;
int n;
ll k;
int main()
{
    cin>>n>>k;
    cin>>str;
    cout<<pam.init(str,k)<<endl;
    return 0;
}

