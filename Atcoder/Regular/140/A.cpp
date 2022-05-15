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
int n,K,a[MAXN];
string str;
int cnt[26];
int main()
{
    scanf("%d%d",&n,&K);
    cin>>str;
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        if(n%i) continue;
        int num=0;
        for(int j=0;j<i;j++)
        {
            memset(cnt,0,sizeof(cnt));
            int maxi=0;
            for(int k=j;k<n;k+=i)
            {
                cnt[str[k]-'a']++;
                maxi=max(maxi,cnt[str[k]-'a']);
            }
            num+=(n/i)-maxi;
        }
        if(num<=K) {ans=i; break;}
    }
    printf("%d\n",ans);
    return 0;
}

