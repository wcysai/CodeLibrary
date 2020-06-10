#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char mp[MAXN][MAXN];
char mp3[10][10]=
{
    "aab",
    "b.b",
    "baa"
};
char mp4[10][10]=
{
    "aaba",
    "ccba",
    "abcc",
    "abaa"
};
char mp5[10][10]=
{
    "aabbc",
    "hii.c",
    "h..jd",
    "g..jd",
    "gffee"
};
char mp6[10][10]=
{
    "aabbcc",
    "def...",
    "def...",
    "...fed",
    "...fed",
    "ccbbaa"
};
char mp7[10][10]=
{
    "aa.bb.c",
    ".ii..jc",
    "h.mm.j.",
    "h...n.d",
    ".l..n.d",
    "gl..kk.",
    "g.ff.ee"
};
vector<int> v;
void construct()
{
    int now=0;
    for(auto x:v)
    {
        for(int i=0;i<x;i++)
            for(int j=0;j<x;j++)
            {
                if(x==3) mp[now+i][now+j]=mp3[i][j];
                else if(x==4) mp[now+i][now+j]=mp4[i][j];
                else if(x==5) mp[now+i][now+j]=mp5[i][j];
                else if(x==6) mp[now+i][now+j]=mp6[i][j];
                else if(x==7) mp[now+i][now+j]=mp7[i][j];
            }
        now+=x;
    }
}
int main()
{
    scanf("%d",&n);
    int tmp=n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mp[i][j]='.';
    if(n==2) {puts("-1"); return 0;} 
    else if(n==3) {v.push_back(3);}
    else if(n==7) {v.push_back(7);}
    else if(n==8) {v.push_back(4); v.push_back(4);}
    else if(n==4) {v.push_back(4);}
    else
    {
        if(n%3==1) {v.push_back(4); n-=4;}
        else if(n%3==2) {v.push_back(5); n-=5;}
        if(n%6==3) {v.push_back(4); v.push_back(5); n-=9;}
        for(int i=0;i<n/6;i++) v.push_back(6);
    }
    construct();
    for(int i=0;i<tmp;i++) printf("%s\n",mp[i]);
}