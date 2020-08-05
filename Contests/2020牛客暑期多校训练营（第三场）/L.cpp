#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
string s="lovely";
int main()
{
    cin>>str;
    bool f=true;
    for(int i=0;i<6;i++)
    {
        if(str[i]!=s[i]&&str[i]!=s[i]-'a'+'A') f=false;
    }
    if(f) puts("lovely"); else puts("ugly");
}