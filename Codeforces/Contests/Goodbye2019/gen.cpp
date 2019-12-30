#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
mt19937 wcy(time(NULL));
int main()
{
    freopen("in.txt","w",stdout);
    string str="";
    for(int i=0;i<200000;i++) 
    {
        int x=wcy()%1;
        str+=(char)'1'+x;
    }
    cout<<str<<endl;
}