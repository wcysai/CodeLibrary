#include<bits/stdc++.h>
using namespace std;
int kmp(string a,string b) // a=pattern, b=text
{
    int n=a.size();
    vector<int> next(n+1,0);
    for(int i=1;i<n;++i)
    {
        int j=i;
        while(j>0)
        {
            j=next[j];
            if(a[j]==a[i])
            {
                next[i+1]=j+1;
                break;
            }
        }
    }
    int cnt=0;
    int m=b.size();
    for(int i=0,j=0;i<m;++i)
    {
        if(j<n&&b[i]==a[j])
        {
            j++;
        }
        else
        {
            while(j>0)
            {
                j=next[j];
                if(b[i]==a[j])
                {
                    j++;
                    break;
                }
            }
        }
        if(j==n)
        {
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int t;
    string a,b;
    scanf("%d",&t);
    while(t--)
    {
        cin>>a;
        cin>>b;
        printf("%d\n",kmp(a,b));
    }
    return 0;
}
