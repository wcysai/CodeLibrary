#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n,k,a[MAXN],b[MAXN];
int p[MAXN];
bool cmp(int x,int y){
    return a[x]>a[y];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    bool f=true;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if((a[i]==a[j])&&(b[i]!=b[j])) f=false;
    if(!f){
        puts("No");
        return 0;
    }
    puts("Yes");
    vector<P> v;
    for(int i=1;i<=n;i++) p[i]=i;
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++){
        
    }
    return 0;
}

