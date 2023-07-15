#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
set<string> s;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        string rts=str; reverse(rts.begin(),rts.end());
        if(rts<str) swap(str,rts);
        s.insert(str);
    }
    printf("%d\n",(int)s.size());
    return 0;
}

