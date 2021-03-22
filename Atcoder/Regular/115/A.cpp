#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
string str[MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    int cnt=0;
    for(int i=0;i<n;i++) 
    {
        cin>>str[i];
        int s=0;
        for(int j=0;j<m;j++) if(str[i][j]=='1') s++;
        if(s&1) cnt++;
    } 
    printf("%lld\n",1LL*cnt*(n-cnt));
    return 0;
}