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
char s[MAXN];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        int cnt=0;
        for(int i=1;i<=n;i++) if(s[i]=='+') cnt++; else cnt--;
        printf("%d\n",max(cnt,-cnt));
    }
    return 0;
}

