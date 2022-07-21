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
int num,maxi,ans;
mt19937 wcy(time(NULL));
string res;
int tot,answer[MAXN];
vector<int> v;
int ask(string &str)
{
    tot++;
    cout<<str<<endl; cout.flush();
    int num;
    scanf("%d",&num);
    if(num==n) exit(0);
    assert(num!=-1);
    return num;
}
void rd()
{
    string str="";
    for(int i=0;i<n;i++) str+=(wcy()&1?'T':'F');
    int num=ask(str);
    if(max(num,n-num)>maxi) {ans=num; maxi=max(num,n-num); res=str;}
}
void solve()
{
    int now=0;
    while(now<n)
    {
        int j=now;
        while(j<n)
        {
            if(j==n-1)
            {
                string str=res;
                str[v[n-1]]='T'+'F'-str[v[n-1]];
                if(ask(str)==ans+1) answer[v[n-1]]=1; else answer[v[n-1]]=0;
                for(int k=j-1;k>=now;k--) answer[v[k]]=1-answer[v[k+1]];
                now=j+1; break;
            }
            else
            {
                string str=res;
                str[v[j]]='T'+'F'-str[v[j]]; str[v[j+1]]='T'+'F'-str[v[j+1]];
                int num=ask(str);
                if(num!=ans) 
                {
                    if(num==ans+2) answer[v[j]]=answer[v[j+1]]=1; else answer[v[j]]=answer[v[j+1]]=0;
                    for(int k=j-1;k>=now;k--) answer[v[k]]=1-answer[v[k+1]];
                    now=j+2; break;
                }
                else j++;
            }
        }
    }
    assert(tot<675);
}
void go()
{
    tot=0;
    string str=res;
    for(int i=0;i<n;i++) if(answer[i]) str[i]='T'+'F'-str[i];
    ask(str);
    assert(0);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) v.push_back(i);
    random_shuffle(v.begin(),v.end());
    maxi=-1;
    for(int i=0;i<1;i++) rd();
    //cout<<"res="<<res<<endl;
    solve(); go();
    return 0;
}

