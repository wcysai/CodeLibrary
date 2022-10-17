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
string s,t;
int main()
{
    scanf("%d",&n);
    cin>>s>>t;
    int cnt=0;
    for(int i=0;i<n;i++)
        if(s[i]!=t[i]) cnt++;
    if(cnt&1) {puts("-1"); return 0;}
    int rem=cnt,now=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i]) printf("0");
        else 
        {
            rem--;
            int t=(s[i]=='0'?1:0);
            if(now+t<=cnt/2&&now+t+rem>=cnt/2) {printf("0"); now+=t;}
            else {printf("1"); now+=(1-t);}
        }
    }
    printf("\n");
    return 0;
}

