#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int m,n;
string str[26]=
{
    "01","1000","1010","100","0",
    "0010","110","0000","00","0111",
    "101","0100","11","10","111",
    "0110","1101","010","000","1",
    "001","0001","011","1001","1011",
    "1100",
};
int dp[MAXN][MAXN];
vector<string> words;
string s;
vector<P> v;
int go_char[MAXN][26];
int go_word[MAXN][MAXN];
int solve_char(int pos,int ch)
{
    for(int i=0;i<(int)str[ch].size();i++)
    {
        if(str[ch][i]=='0')
        {
            if(pos<(int)v.size()&&v[pos].F==0&&max(v[pos].S-1,1-v[pos].S)<=1) pos++;
            else return -1;
        }
        else 
        {
            if(pos<(int)v.size()&&v[pos].F==0&&max(v[pos].S-3,3-v[pos].S)<=1) pos++;
            else return -1;
        }
        if(i!=(int)str[ch].size()-1)
        {
            if(pos<(int)v.size()&&v[pos].F==1&&max(v[pos].S-1,1-v[pos].S)<=1) pos++;
            else return -1;
        }
    }
    return pos;
}
int solve_word(int pos,int id)
{
    for(int i=0;i<(int)words[id].size();i++)
    {
        pos=solve_char(pos,words[id][i]-'A');
        if(pos==-1) return -1;
        if(i!=(int)words[id].size()-1)
        {
            if(pos<(int)v.size()&&v[pos].F==1&&max(v[pos].S-3,3-v[pos].S)<=1) pos++;
            else return -1;
        }
    }
    return pos;
}
bool valid[MAXN];
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        string str;
        cin>>str;
        words.push_back(str);
    }
    sort(words.begin(),words.end());
    int cnt=0;
    while(cnt<n)
    {
        string str;
        cin>>str;
        s+=str;
        cnt+=(int)str.size();
    }
    cnt=0;
    for(int i=0;i<n;i++)
    {
        if(i==0||s[i]==s[i-1]) cnt++;
        else
        {
            if(s[i-1]=='+') v.push_back(P(0,cnt)); 
            else v.push_back(P(1,cnt));
            cnt=1;
        }
    }
    if(s[n-1]=='+') v.push_back(P(0,cnt)); else v.push_back(P(1,cnt));
    int ans=0;
    for(auto p:v) if(p.S%2==0) ans++;
    for(int i=0;i<(int)v.size();i++)
        for(int j=0;j<26;j++)
        {
            go_char[i][j]=solve_char(i,j);
            //if(go_char[i][j]!=-1) printf("%d %d %d\n",i,j,go_char[i][j]);
        }
    for(int i=0;i<(int)v.size();i++)
        for(int j=0;j<(int)words.size();j++)
        {
            go_word[i][j]=solve_word(i,j);
            //if(go_word[i][j]!=-1) printf("%d %d %d\n",i,j,go_word[i][j]);
        }
    memset(valid,false,sizeof(valid));
    valid[(int)v.size()]=true;
    for(int i=(int)v.size()-1;i>=0;i--)
    {
        for(int j=0;j<(int)words.size();j++)
        {
            if(go_word[i][j]!=-1)
            {
                int pos=go_word[i][j];
                if(pos==(int)v.size()) valid[i]=true;
                else if(pos!=(int)v.size()&&valid[pos+1]&&v[pos].F==1&&max(v[pos].S-5,5-v[pos].S)<=1) valid[i]=true;
            }
        }
    }
    if(!valid[0]) puts("-1");
    else 
    {
        printf("%d\n",ans);
        int cur=0;
        while(cur<(int)v.size())
        {
            for(int j=0;j<(int)words.size();j++)
            {
                if(go_word[cur][j]!=-1)
                {
                    int pos=go_word[cur][j];
                    if(pos==(int)v.size()) {cur=(int)v.size(); cout<<words[j]<<endl; break;}
                    else if(pos!=(int)v.size()&&valid[pos+1]&&v[pos].F==1&&max(v[pos].S-5,5-v[pos].S)<=1)
                    {
                        cur=pos+1;
                        cout<<words[j]<<" ";
                        break;
                    }
                }
            }
        }
    }
    return 0;
}