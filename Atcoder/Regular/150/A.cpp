#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        cin>>str;
        vector<int> v;
        for(int i=0;i<n;i++)
            if(str[i]=='1')
                v.push_back(i);
        bool f=true;
        if(v.size()>=2)
        {
            if(v.back()-v[0]+1>k) f=false;
            for(int j=v[0]+1;j<(int)v.back();j++) if(str[j]=='0') f=false;
        }
        if(!f) {puts("No"); continue;}
        if(v.size()==0)
        {
            int last=-1;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(str[i]=='0')
                {
                    cnt+=max(0,i-last-k);
                    last=i;
                }
            }
            cnt+=max(0,n-last-k);
            if(cnt==1) puts("Yes"); else puts("No");
            continue;
        }
        int l=v[0],r=v.back();
        while(r-l+1<k&&l-1>=0&&str[l-1]!='0') l--;
        while(r-l+1<k&&r+1<n&&str[r+1]!='0') r++;
        if(r-l+1==k)
        {
            bool f=true;
            if((l!=0&&str[l-1]!='0')&&(str[r]!='1')) f=false; 
            if((r!=n-1&&str[r+1]!='0')&&(str[l]!='1')) f=false; 
            if(f) puts("Yes"); else puts("No");
        }
        else puts("No");
    }
    return 0;
}

