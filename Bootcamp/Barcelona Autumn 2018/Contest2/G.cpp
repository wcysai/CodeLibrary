/*************************************************************************
    > File Name: G.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-27 16:12:26
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
int N,Q;
set<P> s;
multiset<int> ms;
string str;
char ch[5];
int main()
{
    scanf("%d%d",&N,&Q);
    cin>>str;
    int last=0;
    for(int i=0;i<N;i++)
    {
        if(i>0&&str[i]==str[i-1]) {s.insert(P(last,i-1)); ms.insert(last-i); last=i;}
        else if(i>1&&str[i]==str[i-2]&&last<=i-2) {s.insert(P(last,i-1)); ms.insert(last-i); last=i-1;}
    }
    s.insert(P(last,N-1));ms.insert(N-last);
    for(int i=0;i<Q;i++)
    {
        int x;scanf("%d",&x);scanf("%s",ch);
        x--;str[x]=ch[0];auto it=s.upper_bound(P(x,INF));it--;
        if(it!=s.begin()&&it->F==x)
        {
            it--;
            if(it->S==x)
            {
                if(str[x]!=str[x+1]) continue;
                int l=it.F;
                ms.erase(it.S-it.F+1);s.erase(it);
                it++;int r=it.S;ms.erase(it.S-it.F+1);s.erase(it);
                s.insert(P(l,x-1));ms.insert(x-l);s.insert(P(x,x));ms.insert(1);
                s.insert(P(x+1,r));ms.insert(r-x);
            }
            else
            {
                if(str[x]==str[x-1]) continue;

            }
        }
    }
    return 0;
}
