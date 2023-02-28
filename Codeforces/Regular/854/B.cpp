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
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        bool f1=false,f2=false;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            if(a[i]==1) f1=true; else f2=true;
        }
        if(f1&&f2) {puts("-1"); continue;}
        else if(f1) {puts("0"); continue;}
        vector<P> v;
        while(true){
            int maxi=1,mini=1;
            for(int i=2;i<=n;i++){
                if(a[i]>a[maxi]) maxi=i;
                if(a[i]<a[mini]) mini=i;
            }
            if(a[mini]==a[maxi]) break;
            v.push_back(P(maxi,mini)); a[maxi]=(a[maxi]+a[mini]-1)/a[mini];
        }
        printf("%d\n",(int)v.size());
        for(auto p:v) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}

