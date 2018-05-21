#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
string str;
int q;
int main()
{
    cin>>str;
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y;
        string s;
        cin>>x>>y>>s;
        int len=s.size();
        int cnt=0;
        for(int i=x;i+len<=y+1;i++)
        {
            string a=str.substr(i,len);
            if(a==s) cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
