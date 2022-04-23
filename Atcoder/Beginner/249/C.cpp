#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 16
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k;
int cnt[MAXN][26];
string str[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) 
    {
        cin>>str[i];
        for(int j=0;j<(int)str[i].size();j++) cnt[i][str[i][j]-'a']++;
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++)
    {
        int tmp[26];
        memset(tmp,0,sizeof(tmp));
        for(int j=0;j<n;j++)
            if(i&(1<<j))
                for(int x=0;x<26;x++) tmp[x]+=cnt[j][x];
        int res=0;
        for(int j=0;j<26;j++) if(tmp[j]==k) res++;
        ans=max(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}

