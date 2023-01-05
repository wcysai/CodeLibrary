#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 255
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],last;
int num[MAXN];
bool has[MAXN];
void clear(){
    for(int i=1;i<=n;i++) has[i]=false;
}
int ask(int id){
    printf("? %d ",id);
    for(int i=1;i<=n;i++) if(has[i]) printf("1"); else printf("0");
    printf("\n");
    fflush(stdout);
    clear();
    int x; scanf("%d",&x);
    return x;
}
bool cmp(int x,int y){
    return num[x]>num[y];
}
void answer(){
    for(int i=1;i<=last;i++) has[a[i]]=true;
    printf("! ");
    for(int i=1;i<=n;i++) if(has[i]) printf("1"); else printf("0");
    printf("\n");
    fflush(stdout);
    exit(0);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) has[j]=(i==j?false:true);
        num[i]=ask(i);
    }
    for(int i=1;i<=n;i++) a[i]=i;
    sort(a+1,a+n+1,cmp);
    last=1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=last;j++) has[a[j]]=true;
        if(ask(a[i])) {
            last=i;
        }
    }
    answer();
    return 0;
}

