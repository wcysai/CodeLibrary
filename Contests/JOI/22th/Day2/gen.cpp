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
int n,k,a[MAXN],b[MAXN],c[MAXN];
mt19937 wcy(time(NULL));
int main()
{
    n=100000;
    printf("%d\n",n);
    for(int i=0;i<n-1;i++){
        a[i]=i+1;
        b[i]=wcy()%(i+1);
        c[i]=wcy()%2;
    }
    for(int i=0;i<n-1;i++) printf("%d%c",a[i],i==n-2?'\n':' ');
    for(int i=0;i<n-1;i++) printf("%d%c",b[i],i==n-2?'\n':' ');
    for(int i=0;i<n-1;i++) printf("%d%c",c[i],i==n-2?'\n':' ');
    return 0;
}

