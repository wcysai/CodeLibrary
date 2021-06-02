#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define BASE1 233
#define BASE2 19260817
#define MOD1 998244353
#define MOD2 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
int n;
string s;
vector<string> str[MAXN];
map<P,int> cnt[MAXN];
int hsh[2][MAXN];
int pw[2][MAXN];
void construct_hash(string &t)
{
    hsh[0][0]=0;
    for(int i=0;i<(int)t.size();i++) hsh[0][i+1]=(1LL*hsh[0][i]*BASE1+(t[i]-'a'))%MOD1;
    for(int i=0;i<(int)t.size();i++) hsh[1][i+1]=(1LL*hsh[1][i]*BASE2+(t[i]-'a'))%MOD2;
}
P get_hash(int l,int r)
{
    return make_pair(((1LL*hsh[0][r+1]-1LL*hsh[0][l]*pw[0][r-l+1])%MOD1+MOD1)%MOD1,((1LL*hsh[1][r+1]-1LL*hsh[1][l]*pw[1][r-l+1])%MOD2+MOD2)%MOD2);
}
int main()
{
    scanf("%d",&n);
    pw[0][0]=pw[1][0]=1;
    for(int i=1;i<=400000;i++) pw[0][i]=1LL*pw[0][i-1]*BASE1%MOD1;
    for(int i=1;i<=400000;i++) pw[1][i]=1LL*pw[1][i-1]*BASE2%MOD2;
    for(int i=0;i<n;i++) 
    {
        cin>>s;
        str[(int)s.size()].push_back(s);
    }
    ll ans=0;
    for(int i=1;i<=400000;i++)
    {
        for(auto x:str[i])
        {
            construct_hash(x);
            P p=get_hash(0,i-1);
            ans+=cnt[i][p];
            for(int j=1;j*2<i;j++)
            {
                if(get_hash(0,j-1)==get_hash(i-j,i-1))
                    ans+=cnt[i-2*j][get_hash(j,i-j-1)];
            }
            cnt[i][p]++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}