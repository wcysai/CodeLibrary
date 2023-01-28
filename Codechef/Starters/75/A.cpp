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
string str;
vector<int> cnt;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cin>>str;
        int cnt=0;
        for(int i=0;i<n;i++) if(str[i]=='0') break; else cnt++;
        vector<int> tmp; 
        int c=0;
        for(int i=cnt;i<n;i++){
            if(str[i]=='1') c++;
            else{
                tmp.push_back(c);
                c=0;
            }
        }
        tmp.push_back(c);
        sort(tmp.begin(),tmp.end());
        printf("%d\n",cnt+tmp.back());
    }
    return 0;
}

