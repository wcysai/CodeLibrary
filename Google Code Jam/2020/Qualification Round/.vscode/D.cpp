#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,b;
int type[MAXN];//0:same 1:notsame
int root0,root1;
int state0,state1;
bool same[MAXN];
int ask(int x)
{
    printf("%d\n",x);
    fflush(stdout);
    int y;
    scanf("%d",&y);
    return y;
}
void answer(string &str) 
{
    cout<<str<<endl;
    string s;
    cin>>s;
    if(s=="N") exit(0);
}
int main()
{
    scanf("%d%d",&t,&b);
    while(t--)
    {
        root0=root1=0;
        for(int i=1;i<=b/2;i++)
        {
            if(i%4==1)
            {
                if(root0) state0=ask(root0); else ask(1);
                if(root1) state1=ask(root1); else ask(1);
            }
            int x=ask(i),y=ask(b-i+1);
            if(x==y)
            {
                type[i]=0;
                if(!root0) {root0=i; same[i]=0; state0=x;}
                else same[i]=state0^x;
            }
            else
            {
                type[i]=1;
                if(!root1) {root1=i; same[i]=0; state1=x;}
                else same[i]=state1^x;
            }
        }
        string s="",t="";
        for(int i=1;i<=b/2;i++)
        {
            if(type[i]==0)
            {
                if(!same[i]) {s+=(char)('0'+state0); t+=(char)('0'+state0);}
                else  {s+=(char)('0'+(state0^1)); t+=(char)('0'+(state0^1));}
            }
            else
            {
                if(!same[i]) {s+=(char)('0'+state1); t+=(char)('0'+(state1^1));}
                else  {s+=(char)('0'+(state1^1)); t+=(char)('0'+state1);}
            }
        }
        reverse(t.begin(),t.end());
        s+=t;
        answer(s);
    }
    return 0;
}