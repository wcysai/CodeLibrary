#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
class EllysCodeConstants {
	public:
	string getLiteral(string candidate) {
        string s="0x"; string suffix=""; bool f=true;
        int sz=(int)candidate.size();
        if(sz>=3&&candidate.substr(sz-3)=="LLU") {suffix="LLU"; candidate=candidate.substr(0,sz-3);}
        else if(sz>=3&&candidate.substr(sz-3)=="ULL") {suffix="ULL"; candidate=candidate.substr(0,sz-3);}
        else if(sz>=2&&candidate.substr(sz-2)=="LU") {suffix="LU"; candidate=candidate.substr(0,sz-2);}
        else if(sz>=2&&candidate.substr(sz-2)=="UL") {suffix="UL"; candidate=candidate.substr(0,sz-2);}
        else if(sz>=2&&candidate.substr(sz-2)=="LL") {suffix="LL"; candidate=candidate.substr(0,sz-2);}
        else if(sz>=1&&candidate.substr(sz-1)=="L") {suffix="L"; candidate=candidate.substr(0,sz-1);}
        else if(sz>=1&&candidate.substr(sz-1)=="U") {suffix="U"; candidate=candidate.substr(0,sz-1);}
        if(candidate.size()==0) return "";
        for(int i=0;i<(int)candidate.size();i++)
        {
            if(candidate[i]>='0'&&candidate[i]<='9') s+=candidate[i];
            else if(candidate[i]>='A'&&candidate[i]<='F') s+=candidate[i];
            else if(candidate[i]=='O') s+='0';
            else if(candidate[i]=='I') s+='1';
            else if(candidate[i]=='Z') s+='2';
            else if(candidate[i]=='S') s+='5';
            else if(candidate[i]=='T') s+='7';
            else {f=false; break;}
        }
        if(!f) return ""; else return s+suffix;
		
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
			string candidate          = "DEADBEEF";
			string expected__         = "0xDEADBEEF";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string candidate          = "BABACECA";
			string expected__         = "0xBABACECA";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string candidate          = "TOPCODER";
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string candidate          = "FLU";
			string expected__         = "0xFLU";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string candidate          = "FULL";
			string expected__         = "0xFULL";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string candidate          = "FALL";
			string expected__         = "0xFALL";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string candidate          = "TASTEFUL";
			string expected__         = "0x7A57EFUL";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 7: {
			string candidate          = "OFFICIAL";
			string expected__         = "0x0FF1C1AL";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 8: {
			string candidate          = "OOZE";
			string expected__         = "0x002E";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 9: {
			string candidate          = "ESPRIT";
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 10: {
			string candidate          = "COOL";
			string expected__         = "0xC00L";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 11: {
			string candidate          = "DISEASE";
			string expected__         = "0xD15EA5E";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 12: {
			string candidate          = "SOLVED";
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 13: {
			string candidate          = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 14: {
			string candidate          = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 15: {
			string candidate          = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = EllysCodeConstants().getLiteral(candidate);
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
