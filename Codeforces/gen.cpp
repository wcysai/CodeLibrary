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
mt19937 wcy(time(NULL));
int main(){
    printf("%d\n",2);
    string s;
    for(int i=0;i<10000;i++) s+=(char)('a'+wcy()%26);
    cout<<s<<endl;
    swap(s[1000],s[2000]);
    swap(s[4999],s[5000]);
    cout<<s<<endl;
    return 0;
}

