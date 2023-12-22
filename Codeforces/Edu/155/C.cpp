#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
string str;
int fact[MAXN];
int main()
{
    fact[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    cin>>t;
    while(t--){
        cin>>str;
        int len=1,now=str[0]-'0',cnt=1,res=1;
        for(int i=1;i<(int)str.size();i++){
            if(str[i]-'0'!=now){
                res=1LL*res*cnt%MOD;
                cnt=1;
                len++;
                now=str[i]-'0';
            }
            else{
                cnt++;
            }
        }
        res=1LL*res*cnt%MOD;
        printf("%d %d\n",(int)str.size()-len,1LL*res*fact[(int)str.size()-len]%MOD);
    }
    return 0;
}

