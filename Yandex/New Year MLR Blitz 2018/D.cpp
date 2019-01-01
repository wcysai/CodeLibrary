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
    cin>>str;
    n=str.size();
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int val;
        if(str[i]>='0'&&str[i]<='9') val=str[i]-'0';
        else val=str[i]-'a'+10;
        ans=ans+val;
    }
    printf("%d\n",ans%5);
    return 0;
}

