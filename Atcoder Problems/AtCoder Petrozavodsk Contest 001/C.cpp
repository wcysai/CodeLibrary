#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n,state,a[MAXN];
string S;
int main()
{
	scanf("%d",&n);
	printf("0\n");
	fflush(stdout);
	cin>>S;
	if(S[0]=='V') return 0;
	state=(S[0]=='M'?0:1);
	printf("%d\n",n/2);
	fflush(stdout);
	cin>>S;
	if(S[0]=='V') return 0;
	int lb,rb;
	if(S[0]=='M'&&state==0)
	{
		if((n/2-1)&1)
		{
			lb=n/2;
			rb=n;
		}
		else
		{
			lb=0;
			rb=n/2;
		}
	}
	else if(S[0]=='M'&&state==1)
	{
		if((n/2-1)&1)
		{
			lb=0;
			rb=n/2;
			state=3;
		}
		else
		{
			lb=n/2;
			rb=n;
			state=2;
		}
	}
	else if(S[0]=='F'&&state==0)
	{
		if((n/2-1)&1)
		{
			lb=0;
			rb=n/2;
			state=2;
		}
		else
		{
			lb=n/2;
			rb=n;
			state=3;
		}
	}
	else
	{
		state=1;
		if((n/2-1)&1)
		{
			lb=n/2;
			rb=n;
		}
		else
		{
			lb=0;
			rb=n/2;
		}
	}
	while(true)
	{
		int mid=(lb+rb)/2;
		printf("%d\n",mid);
		fflush(stdout);
		cin>>S;
		if(S[0]=='V') return 0;
		if(state==0)
		{
			if(S[0]=='F')
			{
				int len=mid-lb-1;
				if(len&1)
				{
					rb=mid;
					state=2;
				}
				else
				{
					lb=mid;
					state=3;
				}
			}
			else
			{
				int len=mid-lb-1;
				if(len&1) lb=mid; else rb=mid;
			}
		}
		else if(state==1)
		{
			if(S[0]=='M')
			{
				int len=mid-lb-1;
				if(len&1)
				{
					rb=mid;
					state=3;
				}
				else
				{
					lb=mid;
					state=2;
				}
			}
			else
			{
				int len=mid-lb-1;
				if(len&1) lb=mid; else rb=mid;
			}
		}
		else if(state==2)
		{
			if(S[0]=='F')
			{
				int len=mid-lb-1;
				if(len&1)
				{
					rb=mid;
					state=2;
				}
				else
				{
					lb=mid;
					state=1;
				}
			}
			else
			{
				int len=mid-lb-1;
				if(len&1)
				{
					lb=mid;
					state=2;
				}
				else
				{
					rb=mid;
					state=0;
				}
			}
		}
		else
		{
			if(S[0]=='F')
			{
				int len=mid-lb-1;
				if(len&1)
				{
					lb=mid;
					state=3;
				}
				else
				{
					rb=mid;
					state=1;
				}
			}
			else
			{
				int len=mid-lb-1;
				if(len&1)
				{
					rb=mid;
					state=3;
				}
				else
				{
					lb=mid;
					state=0;
				}
			}
		}
	}
	return 0;
}