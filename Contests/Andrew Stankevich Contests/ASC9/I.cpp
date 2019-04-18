#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
bool has[12][12];
string s,t;
int main()
{
    freopen("traces.in","r",stdin);
    freopen("traces.out","w",stdout); 
    scanf("%d%d",&n,&m);
    memset(has,false,sizeof(has));
    for(int i=0;i<m;i++)
    {
        cin>>s;
        int x=s[0]-'a'+1,y=s[1]-'a'+1;
        has[x][y]=has[y][x]=true;
    }
    cin>>s; cin>>t;
    if(s.size()!=t.size())
    {
        puts("NO");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int cnt0=0,cnt1=0;
        for(int j=0;j<(int)s.size();j++)
        {
            if(s[j]-'a'+1==i) cnt0++;
            if(t[j]-'a'+1==i) cnt1++;
        }
        if(cnt0!=cnt1)
        {
            puts("NO");
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(!has[i][j])
            {
                string ss="",tt="";
                for(int k=0;k<(int)s.size();k++)
                {
                    int x=s[k]-'a'+1;
                    if(x==i||x==j) ss+=s[k];   
                }
                for(int k=0;k<(int)t.size();k++)
                {
                    int x=t[k]-'a'+1;
                    if(x==i||x==j) tt+=t[k];   
                }
                if(ss!=tt)
                {
                    puts("NO");
                    return 0;
                }
            }
        }
    puts("YES");
    return 0;
}
