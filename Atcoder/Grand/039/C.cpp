#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string str;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int res[MAXN];
int get_val(string str)
{
    int x=0;
    for(int i=0;i<(int)str.size();i++)
    {
        x=2LL*x%MOD;
        if(str[i]=='1') add(x,1);
    }
    return x+1;
}
bool check(string x)
{
    int m=x.size();
    string rx=x; for(int i=0;i<m;i++) rx[i]=('0'+'1'-rx[i]);
    string ss="";
    string tmp=str; for(int i=0;i<n;i++) tmp[i]=('0'+'1'-tmp[i]);
    for(int i=0;i<(2*n/m);i++)
    {
        if(i&1) ss+=rx;
        else ss+=x;
    }
    for(int i=0;i<(2*n)%m;i++)
    {
        if((n/m)&1) ss+=rx[i];
        else ss+=x[i];
    }
    return ss<=(str+tmp);
}
int get_ans(int x)
{
    if((2*n/x)%2==0) return 0;
    string t=str.substr(0,x/2);
    int ret=get_val(t);
    if(!check(t)) dec(ret,1);
    return ret;
}
int main()
{
    scanf("%d",&n);
    cin>>str;
    int ans=0;
    for(int i=1;i*i<=2*n;i++)
    {
        if(2*n%i) continue;
        res[i]=get_ans(i);
        res[2*n/i]=get_ans(2*n/i);
    }
    for(int i=1;i<=2*n;i++)
    {
        add(ans,1LL*i*res[i]%MOD);
        for(int j=2*i;j<=2*n;j+=i) if(res[j]) dec(res[j],res[i]);
    }
    printf("%d\n",ans);
    return 0;
}
