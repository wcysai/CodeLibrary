#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 6005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
char s[MAXN];
int ways[MAXN][MAXN],cont[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    ways[0][n]=1; cont[0][n]=0;
    for(int i=0;i<2*n;i++)
        for(int j=-n;j<=n;j++){
            if(!ways[i][j+n]) continue;
            if(j!=n&&s[i+1]=='?'||s[i+1]=='+'){
                add(ways[i+1][j+1+n],ways[i][j+n]);
                add(cont[i+1][j+1+n],cont[i][j+n]);
                if(j<0) add(cont[i+1][j+1+n],1LL*ways[i][j+n]*i%MOD); 
                else dec(cont[i+1][j+1+n],1LL*ways[i][j+n]*i%MOD); 
            }
            if(j!=-n&&s[i+1]=='?'||s[i+1]=='-'){
                add(ways[i+1][j-1+n],ways[i][j+n]);
                add(cont[i+1][j-1+n],cont[i][j+n]);
                if(j>0) add(cont[i+1][j-1+n],1LL*ways[i][j+n]*i%MOD); 
                else dec(cont[i+1][j-1+n],1LL*ways[i][j+n]*i%MOD); 
            }
        }
    printf("%d\n",cont[2*n][n]);
    return 0;
}

