#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int sz;
vector<int> v;
int cnt[10],cnt2[10];
string str,ans;
void dfs(int now,int sum)
{
    if(now==sz)
    {
        memset(cnt,0,sizeof(cnt));
        memset(cnt2,0,sizeof(cnt2));
        for(int i=0;i<2*sz;i+=2)
        {
            cnt[str[i+1]-'0']+=str[i]-'0';
            cnt2[str[i+1]-'0']++; cnt2[str[i]-'0']++;
        }
        bool f=true;
        for(int i=0;i<10;i++) if(cnt[i]!=cnt2[i]) f=false;
        if(f)
        {
            vector<string> vv; vv.clear();
            for(int i=0;i<2*sz;i+=2)
            {
                vv.push_back(str.substr(i,2));
                sort(vv.begin(),vv.end());
            }
            string tmp="";
            for(auto s:vv) tmp+=s;
            if(ans=="") ans=tmp;
            ans=min(ans,tmp);
        }
        return;
    }
    for(int i=0;i<(int)v.size();i++)
    {
        if(v[i]==0) continue;
        if(sum+v[i]>2*sz) return;
        str+=(char)('0'+v[i]);
        str+=(char)('0'+v[now]);
        dfs(now+1,sum+v[i]);
        str.pop_back();
        str.pop_back();
    }
}
class SelfDescFind {
	public:
	string construct(vector <int> digits) {
		v=digits; sz=(int)v.size();
        ans="";
        dfs(0,0);
        return ans;
	}
};
// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int digits[]              = {0,1,2,3,4,5,6,7,8,9};
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int digits[]              = {2};
			string expected__         = "22";

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int digits[]              = {0,1,3,4};
			string expected__         = "10143133";

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int digits[]              = {0,1,2,4,5,6,8,9};
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int digits[]              = {0,1,2,3,5,6,8,9};
			string expected__         = "1016181923253251";

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int digits[]              = {4};
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int digits[]              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int digits[]              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int digits[]              = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SelfDescFind().construct(vector <int>(digits, digits + (sizeof digits / sizeof digits[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
