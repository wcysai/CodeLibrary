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
char str[MAXN];
char ans[MAXN];
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    int now=1,tot=1;
    while(now<=n){
        if(now<n&&str[now]=='n'&&str[now+1]=='a'){
            ans[tot]='n';
            ans[tot+1]='y';
            ans[tot+2]='a';
            tot+=3; now+=2;
        }
        else{
            ans[tot]=str[now];
            tot++; now++;
        }
    }
    printf("%s\n",ans+1);
    return 0;
}

