#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        vector<int> v;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); v.push_back(a[i]);}
        sort(v.begin(),v.end());
        int maxi=-1,cnt=0;
        for(int i=0;i<(int)v.size();i++){
            if(m>=v[i]){
                cnt++;
                maxi=max(maxi,v[i]);
                m-=v[i];
            }
        }
        if(cnt==0) printf("%d\n",n+1);
        else if(cnt==n) printf("%d\n",1);
        else printf("%d\n",a[cnt+1]<=maxi+m?n-cnt:n-cnt+1);
    }
    return 0;
}

