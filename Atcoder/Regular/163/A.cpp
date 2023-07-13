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
int T,n,k,a[MAXN];
string str;
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        cin>>str;
        bool f=false;
        for(int i=1;i<n;i++){
            //cout<<str.substr(0,i)<<" "<<str.substr(i)<<endl;
            if(str.substr(0,i)<str.substr(i)){
                puts("Yes"); f=true; break;
            }
        }
        if(!f) puts("No");
    }
    return 0;
}

