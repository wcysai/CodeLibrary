#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string s[MAXN],x;
int rk[26];
bool cmp(string s,string t)
{
    for(int i=0;i<min(s.size(),t.size());i++)
    {
        if(s[i]!=t[i]) return rk[s[i]-'a']<rk[t[i]-'a'];
    }
    return s.size()<t.size();
}
int main()
{
    cin>>x;
    for(int i=0;i<26;i++) rk[x[i]-'a']=i;
    scanf("%d",&n);
    for(int i=0;i<n;i++) cin>>s[i];
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++) cout<<s[i]<<endl;
    return 0;
}