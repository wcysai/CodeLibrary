#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string s[MAXN];
int pr,sum;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int prime[MAXN],fact[MAXN];
bool is_prime[MAXN];
int get_pr(string &s){
    int n=(int)s.size();
    vector<int> nxt(n+1,0);
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0){
            j=nxt[j];
            if(s[j]==s[i]){
                nxt[i+1]=j+1;
                break;
            }
        }
    }
    if(nxt[n]>0&&n%(n-nxt[n])==0) return n-nxt[n]; else return n;
}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int sieve(int n){
    int p=0;
    for(int i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]) {prime[p++]=i; fact[i]=i;}
        for(int j=0;j<p;j++){
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            fact[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
map<int,int> mp;
vector<P> fac;
void factorize(int x){
    fac.clear();
    while(x>1){
        int p=fact[x],cnt=0;
        while(x%p==0) x/=p,cnt++;
        fac.push_back(P(p,cnt));
    }
}
void add_osc(int x){
    bool f=true;
    for(int i=0;i<(int)s[x].size();i++) if(s[x][i]=='0') f=false;
    if(f) {pr=1; sum=2; mp.clear(); return;}
    int now=0,cur=0,ss=0,cnt=0,sz=(int)s[x].size();
    do{
        if(s[x][now]=='1'){
            now++; if(now==sz) now=0; 
        }
        else{
            now++; if(now==sz) now=0; ss++;
            while(s[x][now]=='1'){
                now++; if(now==sz) now=0; ss++;
            }
            now++; if(now==sz) now=0; 
        }
        cnt++;
    }while(now!=0);
    //printf("cnt=%d ss=%d\n",cnt,ss);
    factorize(ss);
    int g=1;
    for(auto p:fac){
        for(int i=0;i<min(p.S,mp[p.F]);i++) g=g*p.F;
        mp[p.F]-=min(p.S,mp[p.F]);
    }
    //need pr/g iterations
    int invg=pow_mod(g,MOD-2);
    int iter=1LL*pr*invg%MOD;
    int num=1LL*iter*ss%MOD,res=2LL*cnt*iter%MOD;
    add(res,1LL*num*pow_mod(pr,MOD-2)%MOD*sum%MOD);
    sum=res;
    factorize(cnt);
    pr=iter;
    for(auto p:fac){
        mp[p.F]+=p.S;
    }
    pr=1LL*iter*cnt%MOD;
}
int main()
{
    sieve(2000000);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        cin>>s[i]; 
        //printf("%d\n",get_pr(s[i]));
        s[i]=s[i].substr(0,get_pr(s[i]));
    }
    pr=1; sum=2;
    for(int i=n;i>=1;i--) 
    {
        add_osc(i);
        //printf("pr=%d sum=%d\n",pr,sum);
    }
    printf("%d\n",sum);
    return 0;
}

