#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
string str;
int cnt[4];
bool check(int x)
{
    cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='2')
        {
            if(cnt[0]<x) cnt[0]++;
            else if(cnt[2]<cnt[1]) cnt[2]++;
        }
        else if(str[i]=='0')
        {
            if(cnt[1]<cnt[0]) cnt[1]++;
            else if(cnt[3]<cnt[2]) cnt[3]++;
        }
    }
    return cnt[3]==x;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        cin>>str;
        int l=0,r=n+1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(check(mid)) l=mid; else r=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}