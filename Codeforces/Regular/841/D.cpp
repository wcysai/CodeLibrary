#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int t,n,m;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        mat a(n,vec(m,0));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        int l=1,r=min(n,m)+1;
        while(r-l>1){
            int mid=(l+r)/2;
            mat b(n,vec(m));
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                {
                    if(a[i][j]>=mid) b[i][j]=1; else b[i][j]=0;
                    if(i) b[i][j]+=b[i-1][j];
                    if(j) b[i][j]+=b[i][j-1];
                    if(i&&j) b[i][j]-=b[i-1][j-1];
                }
            bool f=false;
            for(int i=mid-1;i<n;i++)
                for(int j=mid-1;j<m;j++){
                    int s=b[i][j]-(i==mid-1?0:b[i-mid][j])-(j==mid-1?0:b[i][j-mid])+(((i==mid-1)||(j==mid-1))?0:b[i-mid][j-mid]);
                    if(s==mid*mid) {f=true; break;}
                }
            if(f) l=mid; else r=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}

