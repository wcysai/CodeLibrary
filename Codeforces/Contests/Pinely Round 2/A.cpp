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
int t,n,a,q;
string str;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&a,&q);
        int maxi=a,num=a;
        cin>>str;
        for(int i=0;i<q;i++){
            if(str[i]=='-') a--; else {a++; num++;}
            maxi=max(maxi,a); 
        }
        if(maxi==n) puts("YES"); else if(num>=n) puts("MAYBE"); else puts("NO");
    }
    return 0;
}

