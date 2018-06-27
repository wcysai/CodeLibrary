#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class fastIO{
private:
	char s[1000010];
	int cnt,size;
	bool stop;
	FILE *fin;
	inline void read(){
		if(cnt>=size){
			size=fread(s,1,1e6,fin);
			cnt=0;
			if(size<=0)
				stop=1;
		}
	}
public:
	fastIO(FILE *f){
		fin=f;
		size=0;
		cnt=0;
		stop=0;
		read();
	}
	inline bool read(int& x){
		x=0;
		while(cnt<size&&(s[cnt]==' '||s[cnt]=='\n')){
			cnt++;
			read();
		}
		while(!stop&&cnt<size&&s[cnt]!=' '&&s[cnt]!='\n'){
			x=x*10+s[cnt]-'0';
			cnt++;
			read();
		}
		return !stop;
	}
	inline bool read(ll& x){
		x=0;
		while(cnt<size&&(s[cnt]==' '||s[cnt]=='\n')){
			cnt++;
			read();
		}
		while(!stop&&cnt<size&&s[cnt]!=' '&&s[cnt]!='\n'){
			x=x*10+s[cnt]-'0';
			cnt++;
			read();
		}
		return !stop;
	}
	inline int read(char x[]){
		int len=0;
		while(cnt<size&&(s[cnt]==' '||s[cnt]=='\n')){
			cnt++;
			read();
		}
		while(!stop&&cnt<size&&s[cnt]!=' '&&s[cnt]!='\n'){
			x[len++]=s[cnt++];
			read();
		}
		if(stop)
			return -1;
		x[len]='\0';
		return len;
	}
		inline int read(string& x){
		int len=0;
		while(cnt<size&&(s[cnt]==' '||s[cnt]=='\n')){
			cnt++;
			read();
		}
		while(!stop&&cnt<size&&s[cnt]!=' '&&s[cnt]!='\n'){
			x+=s[cnt++];
			read();
		}
		if(stop)
			return -1;
		return len;
	}
};
bool kmp(string a,string b) // a=pattern, b=text
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
            return true;
    }
    return false;
}
int query,n;
int main()
{
    fastIO fin(stdin);
    vector<string> save;
    fin.read(query);
    int k=0,t=0,len=0;
    while(query--)
    {
        t=0,len=0;
        save.clear();
        fin.read(n);
        for(int i=0;i<n;i++)
        {
            string str;
            fin.read(str);
            save.push_back(str);
            if(str.size()>len) {len=str.size(); t=i;}
        }
        bool f=true;
        for(int i=0;i<n;i++)
        {
            if(!kmp(save[i],save[t]))
            {
                printf("No\n");
                f=false;
                break;
            }
        }
        if(f) cout<<save[t]<<endl;
    }
    return 0;
}

