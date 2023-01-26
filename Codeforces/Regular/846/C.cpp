#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN],cnt[MAXN],c[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        for(int i=1;i<=m;i++) scanf("%d",&c[i]);
        sort(c+1,c+m+1,greater<int>());
        priority_queue<int> pque; 
        while(pque.size()) pque.pop();
        for(int i=1;i<=n;i++) if(cnt[i]) pque.push(cnt[i]);
        int ans=0;
        for(int i=1;i<=m;i++){
            if(!pque.size()) break;
            int v=pque.top(); pque.pop();
            if(v<=c[i]) ans+=v;
            else{
                ans+=c[i];
                pque.push(v-c[i]);
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++) cnt[i]=0;
    }
    return 0;
}

