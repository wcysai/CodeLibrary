#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef unsigned long long ull;
int t,fact[MAXN];
string str;
vector<P> v;
int main()
{
    fact[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        v.push_back(P(0,0));
        int ans=1;
        for(int i=0;i<(int)str.size();i++)
        {
            if(str[i]>='0'&&str[i]<='9') continue;
            if(str[i]=='(') v.push_back(P(0,0));
            else if(str[i]==')') 
            {
                P p=v.back(); v.pop_back();
                ans=1LL*fact[p.F]*ans%MOD;
                ans=1LL*fact[p.S]*ans%MOD;
            }
            else if(str[i]=='*')
            {
                P p=v.back(); v.pop_back(); p.F++; v.push_back(p);
            }
            else
            {
                P p=v.back(); v.pop_back(); p.S++; v.push_back(p);
            }
        }
        assert(v.size()==1);
        P p=v.back(); v.pop_back();
        ans=1LL*fact[p.F]*ans%MOD;
        ans=1LL*fact[p.S]*ans%MOD;
        printf("%d\n",ans);
    }
    return 0;
}