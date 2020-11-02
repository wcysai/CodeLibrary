#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T;
char str[MAXN];
char ch;
int main()
{
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        string t="";
        bool add=false;
        ch=getchar();
        while(ch!='\n')
        {
            if(ch==':'||ch=='-')
            {
                if(!t.size()||(t.size()&&t.back()==' ')) t+=ch;
                else
                {
                    t+=' ';
                    t+=ch;
                }
                t+=' ';
                add=true;
            }
            else 
            {
                if(ch==' '&&add) t.pop_back();
                t+=ch;
                add=false;
            }
            ch=getchar();
        }
        if(add) t.pop_back();
        cout<<t<<endl;
    }
    return 0;
}