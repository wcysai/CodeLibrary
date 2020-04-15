#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N;
string s[MAXN];
string pre[MAXN],suf[MAXN];
int main()
{
    scanf("%d",&T);
    for(int _=1;_<=T;_++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++) cin>>s[i];    
        printf("Case #%d: ",_);
        string ppre="",ssuf="";
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<(int)s[i].size();j++)
            {
                if(s[i][j]=='*')
                {
                    pre[i]=s[i].substr(0,j);
                    if(pre[i].size()>ppre.size()) ppre=pre[i];
                    break;
                }
            }
            for(int j=(int)s[i].size()-1;j>=0;j--)
            {
                if(s[i][j]=='*')
                {
                    suf[i]=s[i].substr(j+1,(int)s[i].size()-1-j);
                    if(suf[i].size()>ssuf.size()) ssuf=suf[i];
                    break;
                }
            }
        }
        int x=(int)ppre.size(),y=(int)ssuf.size();
        bool f=true;
        for(int i=0;i<N;i++) 
        {
            if(ppre=="") continue;
            if(ppre.substr(0,(int)pre[i].size())!=pre[i]) f=false;
        }
        for(int i=0;i<N;i++) 
        {
            if(ssuf=="") continue;
            if(ssuf.substr(y-(int)suf[i].size(),(int)suf[i].size())!=suf[i]) f=false;
        }
        if(!f) puts("*");
        else
        {
            string ans=ppre;
            for(int i=0;i<N;i++)
            {
                 for(int j=0;j<(int)s[i].size();j++)
                {
                    if(s[i][j]!='*')
                    {
                        ans+=s[i][j];
                    }
                }
            }
            ans+=ssuf;
            cout<<ans<<endl;
        }
    }
    return 0;
}