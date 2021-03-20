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
string s,t;
int main()
{
    scanf("%d",&n);
    cin>>s; cin>>t;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        bool f=true;
        for(int j=0;j<i;j++) if(s[n-i+j]!=t[j]) f=false;
        if(f) cnt=i;
    }
    printf("%d\n",2*n-cnt);
    return 0;
}