#include<bits/stdc++.h>
using namespace std;
set<string >se;
class CrazyCrazy {
	public:
	string possible(string song) {
        int n=(int)song.size();
        for(int mask=0;mask<(1<<(n/2));mask++)
        {
            string s="",t="";
            for(int i=0;i<n/2;i++)
            {
                if(mask&(1<<i)) s+=song[i];
                    else t+=song[i];
            }
            if(s.size()<t.size()) continue;
            int szs=(int)s.size(),szt=(int)t.size();
            if(s.substr(0,szt)!=t) continue;
            se.insert(s.substr(szt,szs-szt));
        }
        for(int mask=0;mask<(1<<(n/2));mask++)
        {
            string s="",t="";
            for(int i=n/2;i<n;i++)
            {
                if(mask&(1<<(i-n/2))) s+=song[i];
                    else t+=song[i];
            }
            if(s.size()<t.size()) continue;
            int szs=(int)s.size(),szt=(int)t.size();
            if(s.substr(szs-szt,szt)!=t) continue;
            string need=s.substr(0,szs-szt);
            if(se.count(need)) return "possible";
        }
        return "impossible";
	}
};


// Powered by FileEdit
// Powered by moj 4.18 [modified TZTester]

// Powered by CodeProcessor
