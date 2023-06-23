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
string str[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>str[i];
        scanf("%d",&a[i]);
    }
    int id=0;
    for(int i=1;i<n;i++) if(a[i]<a[id]) id=i;
    for(int i=0;i<n;i++) {
        int x=(i+id)%n;
        cout<<str[x]<<endl;
    }
    return 0;
}

