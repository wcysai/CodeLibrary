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
char str[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        scanf("%s",str+1);
        if(k&1){
            vector<char> v1,v2;
            for(int i=1;i<=n;i+=2){
                v1.push_back(str[i]);
            }
            for(int i=2;i<=n;i+=2){
                v2.push_back(str[i]);
            }
            sort(v1.begin(),v1.end()); sort(v2.begin(),v2.end());
            for(int i=1;i<=n;i+=2){
                str[i]=v1[i/2];
            }
            for(int i=2;i<=n;i+=2){
                str[i]=v2[i/2-1];
            }
        }
        else sort(str+1,str+n+1);
        for(int i=1;i<=n;i++) printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}

