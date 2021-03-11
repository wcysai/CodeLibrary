#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
string str;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        n=(int)str.size();
        int cnta=0,cntb=0,tmp=n;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='a') {cnta++; tmp=n-1-i;}
            else cntb++;
        }
        if(cntb==0||cnta==0) {cout<<str<<endl; continue;}
        if(str[n-1]=='a')
        {
            int cnt=1,now=n-2;
            while(str[now]=='a') {cnt++; now--;}
            int cur=0,res=0;
            for(int i=0;i<=now;i++)
            {
                if(str[i]=='a')
                {
                    cur++;
                }
                else 
                {
                    res+=max(0,cur-2);
                    cur=0;
                }
            }
            cnt+=res;
            if((cnta-cnt)&1) cnt--;
            for(int i=0;i<cntb;i++) printf("b");
            for(int j=0;j<cnt;j++) printf("a");
            puts("");
        }
        else if(cnta%2==0)
        {
            for(int i=0;i<cntb;i++) printf("b");
            puts("");
            continue;
        }
        else if(tmp==cntb)
        {
            printf("a");
            for(int i=0;i<cntb;i++) printf("b");
            puts("");
            continue;
        }
        else if(n>=3&&str[n-1]=='b'&&str[n-2]=='b'&&str[n-3]=='b')
        {
            for(int i=0;i<cntb-2;i++) printf("b");
            int cur=0,res=0,maxi=0;
            for(int i=0;i<n;i++)
            {
                if(str[i]=='a')
                {
                    cur++;
                }
                else 
                {
                    maxi=max(maxi,cur);
                    res+=max(0,cur-2);
                    cur=0;
                }
            }
            if(res==0) res=maxi; else res+=2;
            if((cnta-res)&1) res--;
            for(int i=0;i<res;i++) printf("a");
            puts("");
            continue;
        }
        else
        {
            for(int i=0;i<cntb-tmp;i++) printf("b");
            printf("a");
            for(int i=0;i<tmp;i++) printf("b");
            puts("");
            continue;
        }
    }
    return 0;
}