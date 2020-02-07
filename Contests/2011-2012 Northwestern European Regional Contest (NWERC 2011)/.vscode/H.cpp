#include<bits/stdc++.h>
#define MAXN 45005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,dp[(1<<13)];
bool possible[(1<<13)];
string str[15];
map<char,int> mp;
int main()
{
    for(int i=0;i<=9;i++) mp['0'+i]=i;
    mp['T']=10; mp['J']=11; mp['Q']=12; mp['K']=13; mp['A']=14;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<13;i++) cin>>str[i];
        memset(possible,false,sizeof(possible));
        for(int mask=1;mask<(1<<13);mask++)
        {
            vector<int> v;
            for(int i=0;i<13;i++)
            {
                if(mask&(1<<i)) v.push_back(mp[str[i][0]]);
            }
            sort(v.begin(),v.end());
            if(v.size()>=5)
            {
                bool f=true;
                for(int i=1;i<=(int)v.size()-1;i++) if(v[i]-v[i-1]!=1) f=false;
                if(f) possible[mask]=true;
            }
            if(v.size()==5)
            {
                if(v[0]==v[1]&&v[2]==v[3]&&v[2]==v[4]) possible[mask]=true;
                if(v[0]==v[1]&&v[1]==v[2]&&v[3]==v[4]) possible[mask]=true;
            }
            bool f=true;
            for(int i=1;i<=(int)v.size()-1;i++) if(v[i]!=v[i-1]) f=false;
            if(f) possible[mask]=true;
        }
        for(int i=0;i<(1<<13);i++) dp[i]=INF;
        dp[0]=0;
        for(int mask=1;mask<(1<<13);mask++)
        {
            int sub=mask;
            do
            {
                sub=(sub-1)&mask;
                if(possible[sub])
                {
                    dp[mask]=min(dp[mask],dp[mask^sub]+1);
                }
            }while(sub!=mask);
        }
        printf("%d\n",dp[(1<<13)-1]);
        int mask=(1<<13)-1;
        while(mask)
        {
            int sub=mask;
            do
            {
                sub=(sub-1)&mask;
                if(possible[sub]&&dp[mask^sub]+1==dp[mask])
                {
                    for(int i=0;i<13;i++)
                    {
                        if(sub&(1<<i)) cout<<str[i]<<' ';
                    }
                    cout<<endl;
                    mask^=sub;
                    break;
                }
            }while(sub!=mask);
        }
    }
    return 0;
}