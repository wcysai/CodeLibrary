#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int pos[MAXN];
int n,t,st[MAXN];
string str;
ll solve(int l,int r)
{
    if(l>r) return 1LL;
    if(pos[r]==l) return solve(l+1,r-1)+1;
    return solve(l,pos[r]-1)*solve(pos[r],r);
}
int main()
{
    freopen("bracket-expression.in","r",stdin);
    freopen("bracket-expression.out","w",stdout);
    cin>>str;
    n=(int)str.size();
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(') st[t++]=i;
        else
        {
            pos[i]=st[t-1];
            t--;
        }
    }
    printf("%lld\n",solve(0,n-1));
    return 0;
}
