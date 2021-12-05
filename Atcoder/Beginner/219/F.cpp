#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
string str;
int n,tot;
ll k;
vector<P> v;
map<P,int> id;
vector<int> res[MAXN];
int get_id(P val)
{
    if(id.find(val)==id.end()) id[val]=++tot;
    return id[val];
}
int main()
{
    cin>>str;
    n=(int)str.size();
    scanf("%lld",&k);
    int x=0,y=0;
    v.push_back(P(x,y));
    for(int i=0;i<n;i++)
    {
        if(str[i]=='L') x--;
        else if(str[i]=='R') x++;
        else if(str[i]=='U') y--;
        else y++;
        v.push_back(P(x,y));
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    if(x==0&&y==0)
    {
        printf("%d\n",(int)v.size());
        return 0;
    }
    for(auto p:v) 
    {
        if(x) 
        {
            int rem=(p.F+200000)/x;
            res[get_id(P(p.F+200000-1LL*rem*x,p.S-1LL*rem*y))].push_back(rem); 
        }
        else
        {
            int rem=(p.S+200000)/y;
            res[get_id(P(p.F-1LL*rem*x,p.S+2000000-1LL*rem*y))].push_back(rem); 
        }
    }
    ll ans=0;
    for(int i=1;i<=tot;i++)
    {
        sort(res[i].begin(),res[i].end());
        for(int j=0;j<(int)res[i].size()-1;j++) ans+=min(k,1LL*(res[i][j+1]-res[i][j]));
        ans+=k;
    }
    printf("%lld\n",ans);
    return 0;
}