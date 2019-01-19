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
    while(scanf("%d",&n)==1)
    {
        if(!n) break;
        bool f=true;
        vector<int> v;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cin>>str;v.clear();
            if(str[0]=='D') f=true; else f=false;
            int now=0;
            for(int i=2;i<(int)str.size();i++)
            {
                if(str[i]==':') {v.push_back(now); now=0;}
                else now=now*10+str[i]-'0';
            }
            v.push_back(now);
            assert((int)v.size()==6);
            if((v[0]<8)||(v[0]==8&&v[1]<30)) {v[0]=8; v[1]=30; v[2]=0;} 
            if(f)
            {
                if((v[0]>9)||(v[0]==9&&v[1]>30)||(v[0]==9&&v[1]==30&&v[2]>0)) cnt++;
                else
                {
                    int s=(v[3]-v[0])*3600+(v[4]-v[1])*60+(v[5]-v[2]);
                    if(s<8*3600) cnt++;
                }
            }
            else
            {
                if((v[0]>12)||(v[0]==12&&v[1]>30)||(v[0]==12&&v[1]==30&&v[2]>0)) cnt++;
                else
                {
                    int s=(v[3]-v[0])*3600+(v[4]-v[1])*60+(v[5]-v[2]);
                    if(s<9*3600) cnt++;
                }
            }
        }
        if(cnt==0) puts("All OK"); else if(cnt>3) puts("Issue Show Cause Letter");
        else printf("%d Point(s) Deducted\n",cnt);
    }
    return 0;
}

