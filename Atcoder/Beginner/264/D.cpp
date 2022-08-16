#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
map<char,int> mp;
string str="atcoder";
string s;
int main()
{
    for(int i=0;i<7;i++) mp[str[i]]=i;
    cin>>s;
    int ans=0;
    for(int i=0;i<7;i++)
        for(int j=i+1;j<7;j++)
            if(mp[s[i]]>mp[s[j]]) ans++;
    printf("%d\n",ans);
    return 0;
}

