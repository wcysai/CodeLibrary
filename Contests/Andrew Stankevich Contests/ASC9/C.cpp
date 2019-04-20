#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
set<string> valid={
    "one","two","three","four","five",
    "six","seven","eight","nine","ten",
    "eleven","twelve","thirteen","fourteen","fifteen",
    "sixteen","seventeen","eighteen","nineteen",
    "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety",
    "hundred","thousand","million","and"
};
map<string,int> tens;
map<string,int> ones;
map<string,int> tenplus;
string tolower(string str)
{
    string t="";
    for(int i=0;i<(int)str.size();i++) t+=tolower(str[i]);
    return t;
}
bool isvalid(string str)
{
    return valid.count(tolower(str));
}
void init()
{
    tens["twenty"]=20; tens["thirty"]=30; tens["forty"]=40; tens["fifty"]=50;
    tens["sixty"]=60; tens["seventy"]=70; tens["eighty"]=80; tens["ninety"]=90;
    ones["one"]=1;  ones["two"]=2; ones["three"]=3; ones["four"]=4; ones["five"]=5;
    ones["six"]=6; ones["seven"]=7; ones["eight"]=8; ones["nine"]=9; ones["ten"]=10;
    tenplus["eleven"]=11; tenplus["twelve"]=12; tenplus["thirteen"]=13;
    tenplus["fourteen"]=14; tenplus["fifteen"]=15; tenplus["sixteen"]=16;
    tenplus["seventeen"]=17; tenplus["eighteen"]=18; tenplus["nineteen"]=19;
}
int solve2(vector<string> words,bool allowzero=false)
{
    if(words.size()==0) return allowzero?0:-1;
    if(words.size()>2) return -1;
    if(words.size()==1)
    {
        if(tens[tolower(words[0])]) return tens[tolower(words[0])];
        if(tenplus[tolower(words[0])]) return tenplus[tolower(words[0])];
        if(ones[tolower(words[0])]) return ones[tolower(words[0])];
        return -1;
    }
    else
    {
        if(tens[tolower(words[0])]&&ones[tolower(words[1])]) return tens[tolower(words[0])]+ones[tolower(words[1])];
        return -1;
    }
}
int solve(vector<string> &words)
{
    if(words.size()==0) return -1;
    for(int i=0;i<(int)words.size();i++)
    {
        if(tolower(words[i])=="hundred")
        {
            if(i!=1) return -1;
            if(!ones[tolower(words[0])]) return -1;
            if(i==(int)words.size()-1) return ones[tolower(words[0])]*100;
            if(tolower(words[i+1])!="and") return -1;
            vector<string> newvec; newvec.clear();
            for(int j=i+2;j<(int)words.size();j++) newvec.push_back(words[j]);
            if(solve2(newvec)==-1) return -1;
            return ones[tolower(words[0])]*100+solve2(newvec);
        }
    }
    return solve2(words);
}
int parse(vector<string> &words)
{
    if(words.size()>17) return -1;
    if(words.size()==1&&tolower(words[0]=="zero")) return 0;
    for(int i=0;i<(int)words.size();i++) if(!isvalid(words[i])) return -1;
    int ret=0,last=0;
    bool hasmillion=false,hasthousand=false;
    for(int i=0;i<(int)words.size();i++)
    {
        if(tolower(words[i])=="million")
        {
            if(hasmillion||hasthousand) return -1;
            vector<string> newvec; newvec.clear();
            for(int j=last;j<i;j++) newvec.push_back(words[j]);
            if(solve(newvec)==-1) return -1;
            ret+=solve(newvec)*1000000;
            hasmillion=true; last=i+1;
        }
        if(tolower(words[i])=="thousand")
        {
            if(hasthousand) return -1;
            vector<string> newvec; newvec.clear();
            for(int j=last;j<i;j++) newvec.push_back(words[j]);
            if(solve(newvec)==-1) return -1;
            ret+=solve(newvec)*1000;
            hasthousand=true; last=i+1;
        }
    }
    if(last==(int)words.size()) return ret;
    vector<string> newvec; newvec.clear();
    for(int j=last;j<(int)words.size();j++) newvec.push_back(words[j]);
    if(solve(newvec)==-1) return -1;
    ret+=solve(newvec);
    return ret;
}
string str;
vector<string> words;
vector<string> separ;
char ch;
P dp[MAXN];
int opt[MAXN];
set<int> newlines;
void solvedp()
{
    if(!words.size()) return;
    for(int i=0;i<=(int)words.size();i++) dp[i]=P(0,0);
    for(int i=(int)words.size()-1;i>=0;i--)
    {
        dp[i]=P(dp[i+1].F,-1);
        opt[i]=-1;
        vector<string> newvec; newvec.clear();
        for(int j=i;j<=min((int)words.size()-1,j+16);j++)
        {
            newvec.push_back(words[j]);
            if(parse(newvec)==-1) continue;
            if(j-i+1+dp[j+1].F>dp[i].F||(j-i+1+dp[j+1].F==dp[i].F&&parse(newvec)>dp[i].S))
            {
                dp[i].F=j-i+1+dp[j+1].F;
                dp[i].S=parse(newvec);
                opt[i]=j;
            }
        }
    }
    int cur=0;
    while(cur<(int)words.size())
    {
        if(dp[cur].S==-1) { printf("%s",words[cur].c_str()); if(cur<(int)separ.size()) printf("%s",separ[cur].c_str()); cur++;}
        else
        {
            vector<string> newvec; newvec.clear();
            for(int j=cur;j<=opt[cur];j++) newvec.push_back(words[j]);
            printf("%d",parse(newvec));
            cur=opt[cur];
            if(cur<(int)separ.size()) printf("%s",separ[cur].c_str()); 
            cur++;
        }
    }
}
int main()
{
    freopen("numbers.in","r",stdin);
    freopen("numbers.out","w",stdout);
    init();
    while((ch=getchar())!=EOF)
    {
        if(ch==' '||ch=='\n')
        {
            if(str.size()>0)
            {
                words.push_back(str);
                string ss=""; ss+=ch;
                separ.push_back(ss);
                str="";
            }
            else if(separ.size()>0) separ[(int)separ.size()-1]+=ch; 
            else putchar(ch);
        }
        else if(isalpha(ch)) str+=ch;
        else
        {
            if(str.size()>0)
            {
                words.push_back(str);
                str="";
            }
            solvedp(); putchar(ch); words.clear(); separ.clear();
        }
    }
    if(str.size()>0) words.push_back(str);
    if(words.size()) solvedp();
    return 0;
}
