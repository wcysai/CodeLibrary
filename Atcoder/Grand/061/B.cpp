#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int c[MAXN][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n%2==0) {puts("No"); continue;}
        puts("Yes");
        int pos=1;
        int cl=0,cr=n;
        for(int i=1;i<=(n+1)/2;i++){
            int l=1,r=pos;
            for(int j=1;j<=n;j++){
                c[l][r]=(j<=cl?cl:cr);
                r++; if(r>n+1) r-=n+1;
                c[l][r]=(j<=cl?cl:cr);
                l++; if(l>n) l-=n;
            }
            cl++; cr--;
            pos=pos+2; if(pos>n+1) pos-=n+1;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n+1;j++)
                printf("%d%c",c[i][j],j==n+1?'\n':' ');
    }
    return 0;
}

