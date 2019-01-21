/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-02 16:17:08
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
int A,B,a,b;
vector<int> ans;
void check(int x)
{
    int last=(A+a)%x;
    int seclast=((A+a)/x)%x;
    if(last==a&&seclast==b) ans.push_back(x);
}
int main()
{
    scanf("%d%d",&A,&B);
    a=B%10,b=B/10;
    A-=a;
    for(int i=1;i*i<=A;i++)
    {
        if(A%i) continue;
        if(i*i==A) check(i);
        else {check(i); check(A/i);}
    }
    if(ans.size()==0) {puts("-1"); return 0;}
    for(auto it:ans) printf("%d ",it);
    return 0;
}

