#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
string s,t;
int cnt[2][26];
bool check(int x){
    int now=n-x;
    for(int i=0;i<n;i++){
        if(t[i]==s[now]) now++; 
        if(now==n) return true;
    }
    return false;
}
int main()
{
    cin>>n;
    cin>>s>>t;
    for(int i=0;i<n;i++){
        cnt[0][s[i]-'a']++;
        cnt[1][t[i]-'a']++;
    }
    bool f=true;
    for(int i=0;i<26;i++) if(cnt[0][i]!=cnt[1][i]) f=false;
    if(!f) {puts("-1"); return 0;}
    int l=0,r=n+1;
    while(r-l>1){
        int mid=(l+r)/2;
        if(check(mid)) l=mid; else r=mid;
    }
    printf("%d\n",n-l);
    return 0;
}

