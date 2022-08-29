#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000015
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<vector<int> > aut;
int pi[MAXN];
string s,t;
int q;
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for(int i=1;i<n;i++) 
    {
        int j=pi[i-1];
        while (j>0&&s[i]!=s[j]) j=pi[j - 1];
        if (s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}
int compute_automaton(string s, vector<vector<int>>& aut) {
  int n = s.size();
  bool same=true;
  for(int i=1;i<n;i++) if(s[i]!=s[i-1]) same=false;
  if(same)
  {
      aut.assign(n+11,vector<int>(26));
        for (int i = 0; i < n+11; i++) {
            for (int c = 0; c < 26; c++) {
                if(c==s[0]-'a') aut[i][c]=i+1; else aut[i][c]=0;
        }
    }
    return n-1;
  }
  vector<int> pi = prefix_function(s);
  aut.assign(n, vector<int>(26));
  for (int i = 0; i < n; i++) {
    for (int c = 0; c < 26; c++) {
      if (i > 0 && 'a' + c != s[i])
        aut[i][c] = aut[pi[i - 1]][c];
      else
        aut[i][c] = i + ('a' + c == s[i]);
    }
  }
  return pi[n-1];
}
int main()
{
    cin>>s;
    int fail;
    if(s.size()>10) fail=compute_automaton(s,aut);
    cin>>q;
    while(q--)
    {
        cin>>t;
        if(s.size()<=10)
        {
            string tmp=s+t;
            vector<int> v=prefix_function(tmp);
            for(int i=(int)s.size();i<(int)tmp.size();i++) printf("%d ",v[i]);
            puts("");
        }
        else
        {
            int tmp=fail;
            for(int i=0;i<(int)t.size();i++)
            {
                tmp=aut[tmp][t[i]-'a'];
                printf("%d ",tmp);
            }
            puts("");
        }
    }
    return 0;
}

