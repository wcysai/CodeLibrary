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
string s,t;
int main()
{
    cin>>s;
    cin>>t;
    n=(int)s.size();
    int x=(t[0]-s[0]+26)%26;
    for(int i=0;i<n;i++)
    {
        s[i]=(s[i]-'a'+x)%26+'a';
    }
    if(s==t) cout<<"Yes"<<endl; else cout<<"No"<<endl;
    return 0;
}