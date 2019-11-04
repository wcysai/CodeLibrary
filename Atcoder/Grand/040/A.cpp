#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str;
int maxl[MAXN],maxr[MAXN];
int main()
{
    cin>>str;
    n=(int)str.size();
    maxl[0]=0; maxr[n]=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='<') maxl[i+1]=maxl[i]+1; else maxl[i+1]=0;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(str[i]=='>') maxr[i]=maxr[i+1]+1; else maxr[i]=0;
    }
    ll sum=0;
    for(int i=0;i<=n;i++) sum+=max(maxl[i],maxr[i]);
    printf("%lld\n",sum);
    return 0;
}
