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
int n;
char str[MAXN];
map<pair<string,string>,int> mp;
int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    for(int mask=0;mask<(1<<n);mask++)
    {
        string str1="",str2="";
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i)) str1+=str[i]; else str2+=str[i];
        }
        mp[make_pair(str1,str2)]++;
    }
    ll ans=0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        string str1="",str2="";
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i)) str1+=str[2*n-1-i]; else str2+=str[2*n-1-i];
        }
        ans+=mp[make_pair(str1,str2)];
    }
    printf("%lld\n",ans);
    return 0;
}

