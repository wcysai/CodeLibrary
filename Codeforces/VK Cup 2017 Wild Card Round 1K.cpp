#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n;
string str;
int main()
{
	scanf("%d",&n);
	cin>>str;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='y')
		{
			cnt=1;
			while(str[i]==str[i+1])
			{
				cnt++;
				i++;
			}
			if(cnt!=2||str[i]=='a'||str[i]=='i'||str[i]=='u'||str[i]=='y') printf("%c",str[i]); else printf("%c%c",str[i],str[i]);
		}
		else
			printf("%c",str[i]);
	}
	return 0;
}