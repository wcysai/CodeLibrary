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
int t,n,k,a[MAXN],cnt[26];
int main()
{
    scanf("%d",&t);
    while(t--){
        memset(cnt,0,sizeof(cnt));
        string str;
        cin>>str;
        for(int i=0;i<(int)str.size();i++){
            cnt[str[i]-'a']++;
        }
        int c=0;
        for(int i=0;i<26;i++) if(cnt[i]>1) c++;
        if(c>1) puts("YES"); else puts("NO");
    }
    return 0;
}

