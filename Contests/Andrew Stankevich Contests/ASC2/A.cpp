#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXK 1005
#define MAXM 26
#define MAXN 65
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define tm sadjoaisjda
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int n,m,k,s,st,tm;
bool ist[MAXK];
int to[MAXK][MAXM];
int go[MAXK][MAXM],res[MAXK][MAXM];
bool vis[MAXK];
bool visv[MAXK][MAXN];
void add(int &a,int b) {a+=b;}
const int base=1000000000;
const int base_digits=9;
inline bool scan_d(int &num)  
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}
struct bigint
{
    vector<int> a;
    int size()
    {
        if(a.empty()) return 0;
        int ans=(a.size()-1)*base_digits;
        int ca=a.back();
        while(ca) ans++,ca/=10;
        return ans;
    }
    bigint(): a(){}
    bigint(int v) {*this=v;}
    void operator=(const bigint &v)
    {
        a=v.a;
    }
    void operator=(int v)
    {
        a.clear();
        for(;v>0;v=v/base) a.push_back(v%base);
    }
    void trim()
    {
        while(!a.empty()&&!a.back()) a.pop_back();
    }
    bigint operator+(const bigint &v) const
    {
        bigint res=v;
        for(int i=0,carry=0;i<(int)max(a.size(),v.a.size())||carry;++i)
        {
            if(i==(int)res.a.size()) res.a.push_back(0);
            res.a[i]+=carry+(i<(int)a.size()?a[i]:0);
            carry=res.a[i]>=base;
            if(carry) res.a[i]-=base;
        }
        return res;
    } 
    friend ostream& operator<<(ostream &stream,const bigint &v)
    {
        stream<<(v.a.empty()?0:v.a.back());
        for(int i=(int)v.a.size()-2;i>=0;i--) 
            stream<<setw(base_digits)<<setfill('0')<<v.a[i];
        return stream;
    }
};
bigint dp[MAXK][MAXN];
bigint solve(int state,int moves)
{
    bigint ret=0; 
    if(visv[state][moves]) return dp[state][moves];
    if(moves==0) 
    {
        visv[state][moves]=true;
        if(ist[state]) ret=1;
        dp[state][moves]=ret;
        return ret;
    }
    for(int i=0;i<m;i++)
    {
        if(res[state][i]==-1) continue;
        ret=ret+solve(res[state][i],moves-1);
    }
    visv[state][moves]=true;
    dp[state][moves]=ret;
    return ret;
}
int main()
{
    freopen("dfa.in","r",stdin);
    freopen("dfa.out","w",stdout);
    cin>>str; m=str.size();
    scan_d(k); scan_d(st);
    memset(ist,false,sizeof(ist));
    scan_d(tm);
    for(int i=0;i<tm;i++)
    {
        int x;scan_d(x);
        ist[x]=true;
    }
    for(int i=1;i<=k;i++)
        for(int j=0;j<m;j++)
            scan_d(to[i][j]);
    for(int i=1;i<=k;i++)
        for(int j=0;j<m;j++)
            scan_d(go[i][j]);
    memset(vis,false,sizeof(vis));
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=k;j++)
        {
            memset(vis,false,sizeof(vis));
            int now=j; 
            while(true) 
            {
                vis[now]=true;
                if(!go[now][i])
                {
                    res[j][i]=to[now][i];
                    break;
                }
                if(vis[to[now][i]]) 
                {
                    res[j][i]=-1;
                    break;
                }
                now=to[now][i];
            }
        }
    }
    scan_d(n);
    memset(visv,false,sizeof(visv));
    bigint ans=solve(st,n);
    cout<<ans<<endl;
    return 0;
}

