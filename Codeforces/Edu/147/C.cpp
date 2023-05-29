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
int t,n,k,a[MAXN];
int val[MAXN];
string str;
int main()
{
    val[1]=1;
    for(int i=2;i<=200000;i++) val[i]=1+val[i/2];
    scanf("%d",&t);
    while(t--){
        cin>>str;
        n=(int)str.size();
        int ans=INF;
        for(int i=0;i<26;i++){
            int res=0,cnt=0;
            for(int j=0;j<n;j++){
                if(str[j]=='a'+i){
                    res=max(res,val[cnt]);
                    cnt=0;
                }
                else cnt++;
            }
            res=max(res,val[cnt]); 
            ans=min(ans,res);
        }
        printf("%d\n",ans);
    }
    return 0;
}

