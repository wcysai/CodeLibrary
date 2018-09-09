/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-09 14:51:07
 ************************************************************************/

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
int T,a[3][3];
int v[25]=
{
    0,0,0,0,0,0,
    10000,36,720,360,80,
    252,108,72,54,180,
    72,180,119,36,360,
    1080,144,1800,3600
};
int perm[10];
int cd[8][3]=
{
    1,2,3,
    4,5,6,
    7,8,9,
    1,4,7,
    2,5,8,
    3,6,9,
    1,5,9,
    3,5,7
};
unordered_map<ll,int> mp[8],cnt;
int save[363000][8];
string str,ch;
int main()
{
    for(int i=1;i<=9;i++) perm[i]=i;
    int tot=0;
    do
    {
        tot++;
        int res=0;
        for(int i=0;i<8;i++)
        {
            res=0;
            for(int j=0;j<3;j++)
                res+=perm[cd[i][j]];
            save[tot][i]=res;
        }
    }while(next_permutation(perm+1,perm+10));
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<8;i++) mp[i].clear();
        cnt.clear();
        ch=" ";
        for(int i=0;i<3;i++) 
        {
            cin>>str;
            ch+=str;
        }
        for(int i=1;i<=9;i++) perm[i]=i;
        tot=0;
        do
        {
            tot++;
            bool f=true;
            for(int i=1;i<=9;i++) 
                if(ch[i]!='#'&&ch[i]!='*'&&(ch[i]-'0')!=perm[i]) 
                    {f=false; break;}
            if(!f) continue;
            ll hash=0,s=1;
            for(int i=1;i<=9;i++)
            {
                if(ch[i]!='#') hash+=1LL*s*perm[i];
                s=s*10;
            }
            for(int i=0;i<8;i++)
                mp[i][hash]+=v[save[tot][i]];
            cnt[hash]++;
        }while(next_permutation(perm+1,perm+10));
        long double ans=0;
        int tot=0;
        for(auto it=cnt.begin();it!=cnt.end();it++)
        {
            int res=0;
            ll id=it->F,last=-1;
            for(int i=0;i<8;i++)
                if(mp[i][id]>res)
                {
                    res=mp[i][id];
                    last=i;
                }
            printf("%d %d\n",last,res);
            tot++;
            ans+=(long double)res/it->S;
        }
        printf("%.10Lf\n",ans/tot);
    }
    return 0;
}

