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
int n,k,a[MAXN];
string str;
int cnt[26];
int main()
{
    cin>>str;
    for(int i=0;i<(int)str.size();i++) cnt[str[i]-'a']++;
    for(int i=0;i<26;i++) {if(cnt[i]==1) {printf("%c\n",'a'+i); return 0;}}
    puts("-1");
    return 0;
}

