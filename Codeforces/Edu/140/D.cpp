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
    scanf("%d",&n);
    cin>>str;
    int s=1,l=1,r=1;
    for(int i=1;i<=n;i++)
    {
        int ch=str[n-i]-'0';
        s=s*2;
        int lb=INF,rb=-INF;
        for(int j=1;j<=(1<<i);j++)
        {
            if(j==1&&ch) continue;
            if(j==(1<<i)&&(!ch)) continue;
            int sm=(ch?j-2:j-1),gr=(ch?(1<<i)-j:(1<<i)-j-1);
            int lowest,highest;
            if(ch) lowest=1+max((sm-gr)/2,0); else lowest=1+(sm+1)/2;
            if(ch) highest=1+sm/2; else {if(sm>=gr) highest=1+gr+(sm-gr)/2; else highest=1+sm;}
            if((lowest>=l&&lowest<=r)||(highest>=l&&highest<=r)) {lb=min(lb,j); rb=max(rb,j);}
        }
        l=lb; r=rb;
    }
    for(int i=l;i<=r;i++) printf("%d%c",i,i==r?'\n':' ');
    return 0;
}

