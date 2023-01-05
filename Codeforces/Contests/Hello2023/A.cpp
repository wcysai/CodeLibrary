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
int t,n,k,a[MAXN];
string str;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cin>>str;
        int cntl=0,cntr=0;
        for(int i=0;i<n;i++){
            if(str[i]=='L') cntl++; else cntr++;
        }
        if((!cntl)||(!cntr)) {puts("-1"); continue;}
        int id=-1;
        for(int i=0;i<n-1;i++){
            if(str[i]=='L'&&str[i+1]=='R') id=i;
        }
        printf("%d\n",id+1);
    }
    return 0;
}

