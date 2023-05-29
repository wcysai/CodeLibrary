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
string str;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>str;
        int cnt=0,res=1;
        for(int i=0;i<(int)str.size();i++){
            if(str[i]=='?'){
                if(i==0) res*=9; 
                else res*=10; 
            }
        }
        if(str[0]=='0'&&str.size()>1) res=0;
        else if((int)str.size()==1&&(str[0]=='0')) res--;
        printf("%d\n",res);
    }
    return 0;
}

