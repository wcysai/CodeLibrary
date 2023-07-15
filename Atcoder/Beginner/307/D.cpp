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
int n,k,a[MAXN];
string str;
int main()
{
    scanf("%d",&n);
    cin>>str;
    string ans="";
    int l=0;
    for(int i=0;i<n;i++){
        if(str[i]==')'&&l){
            while(ans.back()!='(') ans.pop_back();
            ans.pop_back();
            l--;
        }
        else{
            ans+=str[i];
            if(str[i]=='(') l++;
        }
    }
    cout<<ans<<endl;
    return 0;
}

