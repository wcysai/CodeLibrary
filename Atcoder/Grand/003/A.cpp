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
map<char,int> mp;
int cnt[4];
int main()
{
    cin>>str;
    mp['N']=0; mp['W']=1; mp['S']=2; mp['E']=3;
    int n=(int)str.size();
    for(int i=0;i<n;i++) cnt[mp[str[i]]]++;
    bool f=true;
    if(cnt[0]||cnt[2])
    {
        if(!cnt[0]||!cnt[2]) f=false;
    }
    if(cnt[1]||cnt[3])
    {
        if(!cnt[1]||!cnt[3]) f=false;
    }
    if(f) puts("Yes"); else puts("No");
    return 0;
}