#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
char str[MAXN];
int get_val(int x){
    if(x>0) return 0;
    else if(x<0) return 1;
    else return 2;
}
int main(){
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=2;i<=n;i++){
        if(str[i]==str[1]) a[i-1]=1; else a[i-1]=-1;
        a[i-1]+=a[i-2];
    }
    int ans=1;
    for(int i=1;i<=n-1;i++){
        int x=get_val(a[i-1]+1)*3+get_val(a[i]+1);
        int y=get_val(a[i])*3+get_val(a[i]+1);
        if(x!=y) ans++;
    }
    printf("%d\n",ans);
    return 0;
}

