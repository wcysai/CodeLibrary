#include<bits/stdc++.h>
#define MAXN 14
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
int A[8*MAXN];
string S;
mt19937 wcy(time(NULL));
bool evaluate_and(int round,int pos,bool choice);
bool gen()
{
    return wcy()&1;
}
int calc(int pos,int round,int a,int b)
{
    return (1LL*pos*(A[round*8+a*4+b*2]+1)+A[round*8+a*4+b*2+1])%m;
}
bool evaluate_or(int round,int pos)
{
    if(round==n) return pos<=k||pos+k>=m;
    bool tmp=gen();
    return evaluate_and(round,pos,tmp)||evaluate_and(round,pos,!tmp);
}
bool evaluate_and(int round,int pos,bool choice)
{
    bool tmp=gen();
    return evaluate_or(round+1,calc(pos,round,choice,tmp))&&evaluate_or(round+1,calc(pos,round,choice,!tmp));
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    cin>>S;
    for(int i=0;i<8*n;i++) scanf("%d",&A[i]);
    int x=0;
    for(int i=0;i<n;i++)
    {
        if(evaluate_and(i,x,true))
        {
            printf("B");
            x=calc(x,i,true,S[i]=='B');
        }
        else
        {
            printf("T");
            x=calc(x,i,false,S[i]=='B');
        }
    }
    printf("\n");
}