#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
string str;
int main()
{
    cin>>str;
    n=(int)str.size();
    int s=0,cnt=0,maxi=0,mini=0,ans=0,maxs=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='0')
        {
            s--;
            maxi=max(maxi,s);
            mini=min(mini,s);
        }
        else if(str[i]=='1')
        {
            s++;
            maxi=max(maxi,s);
            mini=min(mini,s);
        }
        else
        {
            if(maxi!=0||mini!=0)
            {
                ans=max(ans,maxi-mini+maxs-cnt*2);
                maxs=max(maxs,maxi-mini+cnt*2);
                maxi=0;
                mini=0;
            }
            cnt++;
        }
    }
    if(maxi!=0||mini!=0) ans=max(ans,maxi-mini+maxs-cnt*2);
    printf("%d\n",ans);
    return 0;
}