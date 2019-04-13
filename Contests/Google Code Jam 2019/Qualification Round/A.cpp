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
int T;
string str;
string a,b;
int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        cin>>str;
        printf("Case #%d: ",t);
        int n=(int)str.size();
        int cnt0=0,cnt1=0;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='0') cnt0++;
            if(str[i]=='1') cnt1++;
        }
        if(cnt0+cnt1==n&&cnt1==1)
        {
            printf("5");
            for(int i=0;i<n-2;i++) printf("0");
            printf(" ");
            printf("5");
            for(int i=0;i<n-2;i++) printf("0");
            printf("\n");
            continue;
        }
        a=b="";
        bool f=true;
        for(int i=n-1;i>=0;i--)
        {
            if(str[i]=='5')
            {
                a='2'+a;
                b='3'+b;
                f=!f;
            }
            else if(str[i]=='0')
            {
                a='0'+a;
                b='0'+b;
            }
            else
            {
                if(f)
                {
                    a='1'+a;
                    b=(char)(str[i]-1)+b;
                }
                else
                {
                    b='1'+b;
                    a=(char)(str[i]-1)+a;
                }
                f=!f;
            }
        }
        int id=-1;
        for(int i=0;i<n;i++) if(a[i]!='0') {id=i; break;}
        a=a.substr(id);
        for(int i=0;i<n;i++) if(b[i]!='0') {id=i; break;}
        b=b.substr(id);
        cout<<a<<' '<<b<<endl;
    }
    return 0;
}

