#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
typedef pair<char,int> P;
int t,n;
int cnt[MAXN];
P a[MAXN];
char res[MAXN];
string str;
int main()
{
    cin>>str;
    n=str.size();
    bool f=true;
    for(int i=0;i<n;i++)
    {
        a[i].F=str[i];
        a[i].S=i;
        cnt[str[i]-'a']++;
        if(cnt[str[i]-'a']>n/2)
        {
            f=false;
            break;
        }
    }
    if(!f)
    {
        printf("impossible\n");
        return 0;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        int dest=i+n/2>=n?i+n/2-n:i+n/2;
        res[a[dest].S]=str[a[i].S];
    }
    printf("%s",res);
    return 0;
}
