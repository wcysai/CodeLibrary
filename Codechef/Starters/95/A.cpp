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
string str;
int cnt[4];//O,A,B,AB
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            cin>>str;
            if(str.size()==2) cnt[3]++;
            else if(str[0]=='O') cnt[0]++;
            else if(str[0]=='A') cnt[1]++;
            else cnt[2]++;
        }
        printf("%d\n",cnt[0]+cnt[3]+max(cnt[1],cnt[2]));
    }
    return 0;
}

