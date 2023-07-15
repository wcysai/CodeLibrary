#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
char s[MAXN],l[MAXN],r[MAXN];
int nxt[MAXN][10];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);
        scanf("%d",&n);
        scanf("%s",l+1);
        scanf("%s",r+1);
        int m=strlen(s+1);
        for(int i=0;i<=9;i++) nxt[m+1][i]=nxt[m][i]=m+1;
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<=9;j++)
                nxt[i][j]=nxt[i+1][j];
            nxt[i][s[i+1]-'0']=i+1;
        }
        int now=0;
        for(int i=1;i<=n;i++){
            int maxi=now;
            for(int j=l[i];j<=r[i];j++) maxi=max(maxi,nxt[now][j-'0']);
            now=maxi;
        }
        if(now==m+1) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}

