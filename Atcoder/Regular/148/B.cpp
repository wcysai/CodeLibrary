#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string str,ans;
string pre[MAXN],suf[MAXN];
int main()
{
    scanf("%d",&n);
    cin>>str;
    ans=str;
    for(int i=0;i<n;i++) pre[i]=str.substr(0,i);
    for(int i=0;i<n;i++) suf[i]=str.substr(i+1,n-i);
    for(int i=0;i<n;i++)
    {
        if(str[i]=='p')
        {
            for(int j=i;j<n;j++)
            {
                string cur=str.substr(i,j-i+1);
                reverse(cur.begin(),cur.end());
                for(int k=0;k<(int)cur.size();k++) cur[k]='d'+'p'-cur[k];
                string tmp=pre[i]+cur+suf[j];
                if(tmp<ans) ans=tmp;
            }
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}

