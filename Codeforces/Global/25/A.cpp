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
string str;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cin>>str;
        int sum=0,cur=0,maxi=0;
        for(int i=0;i<n;i++){
            if(str[i]=='0'){
                if(cur){
                    maxi=max(maxi,cur);
                    sum+=cur;
                    cur=0;
                }
            }
            else cur++;
        }
        maxi=max(maxi,cur);
        sum+=cur;
        if (sum%2==1)puts("NO");
        else if(sum==2&&maxi==2) puts("NO");
        else puts("YES"); 
    }
    return 0;
}

