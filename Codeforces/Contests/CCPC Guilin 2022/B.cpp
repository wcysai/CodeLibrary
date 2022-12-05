#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 405
#define MAXM 7
#define INF 4005
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
string str;
int state[MAXM][MAXN],tl[MAXM][MAXN],ml[MAXM][MAXN];
int tmmask[MAXN];
void upd(int &a,int b) {a=min(a,b);}
//0: OK 1: WA 2:TL 3:ML 4:RE
pair<int,P> parse(string str)
{
    int st=0;
    if(str[0]=='O') st=0;
    else if(str[0]=='W') st=1;
    else if(str[0]=='T') st=2;
    else if(str[0]=='M') st=3; else st=4;
    int t=0,m=0;
    int fst=-1;
    for(int i=0;i<(int)str.size();i++)
    {
        if(str[i]>='0'&&str[i]<='9') {if(fst==-1) fst=i;}
        if(str[i]=='/')
        {
            for(int j=fst;j<i;j++) t=t*10+(str[j]-'0');
            for(int j=i+1;j<(int)str.size();j++) m=m*10+(str[j]-'0');
        }
    }
    return make_pair(st,P(t,m));
}
short dp[(1<<18)];
P pre[(1<<18)];
int go(int mask,int i)
{
    int nmask=mask|tmmask[i];
    bool f=true;
    for(int j=0;j<m;j++)
    {
        if((!(mask&(1<<(3*j)))))
        {
            if(tl[j][i]>tl[j][0]||ml[j][i]>ml[j][0]) f=false;
            if(state[j][i]!=0)
            {
                if(state[j][i]!=state[j][0]) f=false;
                else 
                {
                    if(!(nmask&(1<<(3*j+1)))) f=false;
                    if(!(nmask&(1<<(3*j+2)))) f=false;
                    nmask|=(1<<(3*j));
                }
            }
        }
    }
    if(f) return nmask; else return -1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>str;
            auto p=parse(str);
            //printf("st=%d tl=%d ml=%d\n",p.F,p.S.F,p.S.S);
            state[j][i]=p.F;
            tl[j][i]=p.S.F+1;
            ml[j][i]=p.S.S+1;
        }
    }
    int ok=0;
    for(int i=0;i<m;i++)
    {
        int maxt=0,maxm=0;
        for(int j=1;j<=n;j++)
        {
            maxt=max(maxt,tl[i][j]);
            maxm=max(maxm,ml[i][j]);
            if(state[i][j]!=0&&state[i][0]==0)
            {
                state[i][0]=state[i][j];
                tl[i][0]=maxt; ml[i][0]=maxm;
            }
        }
        if(state[i][0]==0) {tl[i][0]=maxt; ml[i][0]=maxm; ok|=(1<<(3*i));}
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++) 
        {
            if(tl[j][i]==tl[j][0]) tmmask[i]|=(1<<(3*j+1));
            if(ml[j][i]==ml[j][0]) tmmask[i]|=(1<<(3*j+2));
        }
        //printf("i=%d tmmask=%d\n",i,tmmask[i]);
    }
    for(int mask=0;mask<(1<<(3*m));mask++) dp[mask]=INF;
    dp[ok]=0;
    for(int mask=0;mask<(1<<(3*m));mask++)
    {
        if(dp[mask]==INF) continue;
        for(int i=1;i<=n;i++)
        {
            int nmask=go(mask,i);
            if(nmask!=-1&&nmask!=mask) 
            {
                if(dp[nmask]>dp[mask]+1)
                {
                    dp[nmask]=dp[mask]+1;
                    pre[nmask]=P(i,mask);
                }
            }
        }
    }
    printf("%d\n",dp[(1<<(3*m))-1]);
    vector<int> ans;
    int mask=(1<<(3*m))-1;
    for(int i=n;i>=1;i--)
    {
        while(mask!=ok)
        {
            ans.push_back(pre[mask].F);
            mask=pre[mask].S;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto x:ans) printf("%d ",x);
    puts("");
    return 0;
}

