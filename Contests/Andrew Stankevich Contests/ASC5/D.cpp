#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
vector<int> v;
vector<int> b;
struct bigint
{
    vector<int> v;
    void clear() {v={0};}
    void add(bigint &rhs)
    {
        int sz=(int)max(v.size(),rhs.v.size());
        int carry=0;
        for(int i=0;i<=sz-1;i++)
        {
            if(i>=(int)v.size()) v.push_back(0);
            int res=v[i]+(i>=(int)rhs.v.size()?0:rhs.v[i])+carry;
            v[i]=res%10;
            carry=res/10;
        }
        if(carry) v.push_back(carry);
    }
    void print()
    {
        while(v.size()>1&&v.back()==0) v.pop_back();
        reverse(v.begin(),v.end());
        int sz=(int)v.size();
        for(int i=0;i<sz;i++) printf("%d",v[i]);
        puts("");
    }
}dp[MAXN][4];
void add(ll &a,ll b) {a+=b;}
void trim()
{
    while(v.size()>0&&v.back()==0) v.pop_back();
}
bool iszero()
{
    return v.size()==0;
}
bool isodd()
{
    if(iszero()||v[0]%2==0) return false;
    return true;
}
void subone()
{
    v[0]--;
    int now=0;
    while(v[now]<0)
    {
        v[now]=10+v[now];
        v[now+1]--;
        now++;
    }
    trim();
}
void divtwo()
{
    int sz=(int)v.size();
    int now=0;
    while(now<=sz-1)
    {
        if(now<sz-1&&v[now+1]&1)
        {
            v[now]=(10+v[now])/2;
            v[now+1]--;
            now++;
        }
        else
        {
            v[now]=v[now]/2;
            now++;
        }
    }
    trim();
}

int main()
{
    freopen("digit.in","r",stdin);
    freopen("digit.out","w",stdout);
    cin>>str;
    for(int i=0;i<(int)str.size();i++) v.push_back((int)str[i]-'0');
    reverse(v.begin(),v.end());
    while(!iszero())
    {
        if(isodd()) {b.push_back(1); subone(); divtwo();}
        else {b.push_back(0); divtwo();}
    }
    reverse(b.begin(),b.end());
    for(int i=0;i<1000;i++)
        for(int j=0;j<4;j++)
            dp[i][j].clear();
    dp[0][0].v.clear(); dp[0][0].v.push_back(1);
    for(int i=0;i<(int)b.size();i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<=min(2,j);k++) if((j-k)*2+b[i]<=3) dp[i+1][(j-k)*2+b[i]].add(dp[i][j]);
        }
    }
    int sz=(int)b.size();
    bigint ans; ans.clear();
    ans.add(dp[sz][0]); ans.add(dp[sz][1]); ans.add(dp[sz][2]);
    ans.print();
    return 0;
}
