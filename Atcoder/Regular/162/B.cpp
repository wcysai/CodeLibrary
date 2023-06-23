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
int n,k,a[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    vector<P> op;
    int inv=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]>a[j]) inv++;
    if(inv&1) {puts("No"); return 0;}
    puts("Yes");
    for(int i=n;i>=3;i--){
        int pos=-1;
        for(int j=1;j<=i;j++){
            if(a[j]==i) {pos=j; break;}
        }
        if(pos==1){
            op.push_back(P(1,1));
            a[1]=a[3]; a[3]=a[2]; a[2]=i; 
            pos=2;
        }
        if(pos!=i){
            op.push_back(P(pos-1,i-2));
            int x=a[pos-1],y=a[pos];
            for(int j=pos+1;j<=i;j++) a[j-2]=a[j];
            a[i-1]=x; a[i]=y;
        }
    }
    printf("%d\n",(int)op.size());
    for(auto p:op) printf("%d %d\n",p.F,p.S);
    return 0;
}

