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
int n,k;
string str[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>str[i];
    }
    bool f=false;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            string tmp=str[i]+str[j];
            bool ff=true;
            int sz=(int)tmp.size();
            for(int k=0;k<sz;k++) if(tmp[k]!=tmp[sz-1-k]) ff=false;
            if(ff) f=true;
        }
    }
    if(f) puts("Yes"); else puts("No");
    return 0;
}

