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
int t,n,k,a[MAXN];
int l[MAXN],r[MAXN],cnt[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            cnt[l[i]]++; cnt[r[i]+1]--;
        }
        int s=0;
        vector<int> v;
        for(int i=1;i<=n;i++)
        {
            s+=cnt[i];
            if(s==n-1&&(l[i]>i||r[i]<i)) v.push_back(i);
        }
        printf("%d\n",(int)v.size());
        for(auto x:v) printf("%d\n",x);
    }
    return 0;
}
