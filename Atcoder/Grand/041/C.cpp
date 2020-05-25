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
char mp3[3][3]
{
    "aab",
    "b.b",
    "baa",
};
char mp4[4][4]
{
    "aaba",
    "ccba",
    "abcc",
    "abaa",
};
char mp5[5][5]
{
    "aabbc",
    "hii.c",
    "h..jd",
    "g..jd",
    "gffee",
};
void construct3(int x)
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            mp[x+i][x+j]=mp3[i][j];
}
void construct4(int x)
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            mp[x+i][x+j]=mp4[i][j];
}
void construct5(int x)
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            mp[x+i][x+j]=mp5[i][j];
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mp[i][j]='.';
    if(n==2) puts("-1"); 
    else 
    {
        int now=0;
        if(n%3==1) {construct4(0); now+=4;}
        else if(n%3==2) {construct5(0); now+=5;}
        while(now<n)
        {
            construct3(now); now+=3;
        }
    }
    for(int i=0;i<n;i++) printf("%s\n",mp[i]);
}