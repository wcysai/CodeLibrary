#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int pos[MAXN];
int main(){
    scanf("%d",&n);
    int x=-1;
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        if(a[i]==-1) x=i;
        else pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        printf("%d%c",x,i==n?'\n':' ');
        x=pos[x];
    }
    return 0;
}

