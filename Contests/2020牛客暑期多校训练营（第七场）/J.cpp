#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef bitset<26> bs;
int N;
bs pt[26];
bs field[26][26];
string str[MAXN];
void process(string str)
{
    if(str[1]=='.')
    {
        int id=str[2]-'a';
        int ptid=str[0]-'A';
        int ptid2=str[6]-'A';
        for(int j=0;j<26;j++)
            if(pt[ptid].test(j))
                field[j][id]|=pt[ptid2];
    }
    else if(str.size()>=7)
    {
        int id=str[6]-'a';
        int ptid=str[0]-'A';
        int ptid2=str[4]-'A';
        for(int j=0;j<26;j++)
            if(pt[ptid2].test(j))
                pt[ptid]|=field[j][id];
    }
    else if(str[4]>='a'&&str[4]<='z')
    {
        int id=str[4]-'a';
        int ptid=str[0]-'A';
        pt[ptid].set(id);
    }
    else
    {
        int ptid1=str[0]-'A';
        int ptid2=str[4]-'A';
        pt[ptid1]|=pt[ptid2];
    }
}
int main()
{
    scanf("%d\n",&N);
    for(int i=0;i<N;i++)
    {
        getline(cin,str[i]);
    }
    for(int i=0;i<6;i++)
        for(int j=0;j<N;j++)
            process(str[j]);
    for(int i=0;i<26;i++)
    {
        printf("%c: ",'A'+i);
        for(int j=0;j<26;j++) if(pt[i].test(j)) printf("%c",'a'+j);
        puts("");
    }
}