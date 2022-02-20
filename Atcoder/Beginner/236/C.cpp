#include<bits/stdc++.h>
#define MAXN 400005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string s[MAXN];
set<string> st;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<m;i++)
    {
        string t;
        cin>>t;
        st.insert(t);
    }
    for(int i=0;i<n;i++)
    {
        if(st.count(s[i])) puts("Yes"); else puts("No");
    }
}