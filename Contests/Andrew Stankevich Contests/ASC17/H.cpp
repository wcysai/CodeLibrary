#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int n,tot;
bool checkdigit(int pos)
{
    if(str[pos]=='-'&&str[pos+1]>='0'&&str[pos+1]<='9') return true;
    if(str[pos]>='0'&&str[pos]<='9'&&str[pos+1]>='0'&&str[pos+1]<='9') return true;
    return false;
}
int main()
{
    freopen("tex.in","r",stdin);
    freopen("tex.out","w",stdout);
    bool nowarnings=true,mathmode=false;
    while(getline(cin,str))
    {
        tot++;
        n=(int)str.size();
        bool escape=false;
        int now=0;
        while(now<n)
        {
            if(escape)
            {
                now++;
                escape=false;
                continue;
            }
            if(str[now]=='\\')
            {
                escape=true;
                now++;
                continue;
            }
            if(str[now]=='$')
            {
                if(now+1<n&&str[now+1]=='$') now+=2; else now++;
                mathmode=!mathmode;
                continue;
            }
            if(mathmode&&(str[now]=='^'||str[now]=='_'))
            {
                if(checkdigit(now+1)) 
                {
                    printf("Warning at line %d, position %d\n",tot,now+1);
                    nowarnings=false;
                }
            }
            now++;
        }   
    }
    if(nowarnings) puts("No warnings");
    return 0;
}
