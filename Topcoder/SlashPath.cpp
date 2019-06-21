#include<bits/stdc++.h>
#define MAXN 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
bool toright[MAXN][MAXN],todown[MAXN][MAXN];
int h,w;
int slash[MAXN][MAXN];
bool check()
{
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
        {
            if(toright[i][j]&&i>1&&j!=w&&slash[i-1][j]==-1&&slash[i-1][j+1]==-1&&slash[i][j+1]==-1&&slash[i][j]==0)
            {
                slash[i][j]=1; slash[i-1][j]=1; slash[i-1][j+1]=0; slash[i][j+1]=1;
                toright[i-1][j+1]=true; todown[i][j+1]=true;
                return true;
            }
            if(todown[i][j]&&j>1&&i!=h&&slash[i][j-1]==-1&&slash[i+1][j-1]==-1&&slash[i+1][j]==-1&&slash[i][j]==0)
            {
                slash[i][j]=1; slash[i][j-1]=1; slash[i+1][j-1]=0; slash[i+1][j]=1;
                todown[i+1][j-1]=true; toright[i+1][j]=true;
                return true;
            }
        }
    return false;
}
class SlashPath {
	public:
	vector <string> construct(int steps) {
		h=49,w=50;
        if(steps%2==0) return vector<string>{};
        int need=h*2+1;
        if(steps<2) return vector<string>{};
        while(need>steps||(steps-need)%4!=0)
        {
            h--; w--;
            need-=2;
        }
        memset(slash,-1,sizeof(slash));
        memset(todown,false,sizeof(todown));
        memset(toright,false,sizeof(toright));
        for(int i=1;i<=h;i++)
        {
            slash[i][i]=slash[i][i+1]=0;
            todown[i][i]=true;
            toright[i][i+1]=true;
        }
        steps-=need;
        assert(steps%4==0);
        while(steps)
        {
            if(check()) steps-=4; else break;
        }
        if(steps) return vector<string>{};
        vector<string> ans;
        for(int i=1;i<=h;i++)
        {
            string str="";
            for(int j=1;j<=w;j++)
            {
                if(slash[i][j]==0) str+="\\";
                else str+="/";
            }
            ans.push_back(str);
        }
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
	
	template<typename T> std::ostream& operator<<(std::ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> std::ostream& operator<<(std::ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int steps                 = 3;
			string expected__[]       = {"\\\\/\\", "/\\\\\\", "\\\\\\\\" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = SlashPath().construct(steps);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int steps                 = 17;
			string expected__[]       = {"\\\\/\\/", "\\\\//\\", "\\//\\/", "\\\\/\\\\" };

			std::clock_t start__      = std::clock();
			vector <string> received__ = SlashPath().construct(steps);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int steps                 = 1234;
			string expected__[]       = { };

			std::clock_t start__      = std::clock();
			vector <string> received__ = SlashPath().construct(steps);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int steps                 = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = SlashPath().construct(steps);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 4: {
			int steps                 = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = SlashPath().construct(steps);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			int steps                 = ;
			string expected__[]       = ;

			std::clock_t start__      = std::clock();
			vector <string> received__ = SlashPath().construct(steps);
			return verify_case(casenum__, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
