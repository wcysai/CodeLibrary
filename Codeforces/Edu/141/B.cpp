#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN][MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int x=1,y=1,l=1,r=n*n;
        for(int i=1;i<=n*n;i++){
            if(i&1) a[x][y]=l++; else a[x][y]=r--;
            if(x&1) {if(y==n) x++; else y++;}
            else {if(y==1) x++; else y--;}
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                printf("%d%c",a[i][j],j==n?'\n':' ');
    }
    return 0;
}

