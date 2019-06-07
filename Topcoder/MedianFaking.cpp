#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> smaller;
vector<int> v;
class MedianFaking {
	public:
	vector <int> minimize(int F, int M, vector <int> data, int goal) {
		int need=(((F*M)&1)?F*M/2:F*M/2-1);
        int cnt=0;
        bool f=false;
        for(int i=0;i<F*M;i++) 
        {
            if(data[i]<goal) cnt++;
            if(data[i]==goal) f=true;
        }
        smaller.resize(F);
        for(int i=0;i<F;i++) smaller[i]=0;
        if(cnt==need) return (f?vector<int>{0,0}:vector<int>{1,1});
        if(cnt<need)
        {
            v.clear();
            for(int i=0;i<F;i++)
            {
                for(int j=i*M;j<(i+1)*M;j++)
                    if(data[j]<=goal) smaller[i]++;
                v.push_back(smaller[i]);
            }
            sort(v.begin(),v.end());
            int val=need-cnt+(f?0:1),dummy=val;
            for(int i=0;i<(int)v.size();i++)
            {
                val-=(M-v[i]);
                if(val<=0) return vector<int>{i+1,dummy};
            }
        }
        else
        {
            v.clear();
            for(int i=0;i<F;i++)
            {
                for(int j=i*M;j<(i+1)*M;j++)
                    if(data[j]<goal) smaller[i]++;
                v.push_back(smaller[i]);
            }
            sort(v.begin(),v.end(),greater<int>());
            int val=cnt-need,dummy=val;
            for(int i=0;i<(int)v.size();i++)
            {
                val-=v[i];
                if(val<=0) return vector<int>{i+1,dummy};
            }
        }
        return vector<int>{0,0};
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

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, std::clock_t elapsed) { 
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
			int F                     = 5;
			int M                     = 5;
			int data[]                = {1,2,3,4,5, 10,9,8,7,6, 25,24,23,22,21, 18,16,17,19,20, 11,13,12,14,15};
			int goal                  = 8;
			int expected__[]          = {1, 5 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = MedianFaking().minimize(F, M, vector <int>(data, data + (sizeof data / sizeof data[0])), goal);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int F                     = 5;
			int M                     = 5;
			int data[]                = {1,2,25,24,23, 3,4,22,21,20, 5,6,19,18,17, 7,16,15,14,13, 8,12,11,10,9};
			int goal                  = 8;
			int expected__[]          = {2, 5 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = MedianFaking().minimize(F, M, vector <int>(data, data + (sizeof data / sizeof data[0])), goal);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int F                     = 1;
			int M                     = 4;
			int data[]                = {10, 40, 30, 20};
			int goal                  = 20;
			int expected__[]          = {0, 0 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = MedianFaking().minimize(F, M, vector <int>(data, data + (sizeof data / sizeof data[0])), goal);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int F                     = 4;
			int M                     = 3;
			int data[]                = {3,8,12, 3,8,12, 3,8,12, 8,12,17};
			int goal                  = 12;
			int expected__[]          = {1, 2 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = MedianFaking().minimize(F, M, vector <int>(data, data + (sizeof data / sizeof data[0])), goal);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int F                     = 5;
			int M                     = 1;
			int data[]                = {10, 20, 30, 40, 50};
			int goal                  = 23;
			int expected__[]          = {1, 1 };

			std::clock_t start__      = std::clock();
			vector <int> received__   = MedianFaking().minimize(F, M, vector <int>(data, data + (sizeof data / sizeof data[0])), goal);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int F                     = ;
			int M                     = ;
			int data[]                = ;
			int goal                  = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = MedianFaking().minimize(F, M, vector <int>(data, data + (sizeof data / sizeof data[0])), goal);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int F                     = ;
			int M                     = ;
			int data[]                = ;
			int goal                  = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = MedianFaking().minimize(F, M, vector <int>(data, data + (sizeof data / sizeof data[0])), goal);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int F                     = ;
			int M                     = ;
			int data[]                = ;
			int goal                  = ;
			int expected__[]          = ;

			std::clock_t start__      = std::clock();
			vector <int> received__   = MedianFaking().minimize(F, M, vector <int>(data, data + (sizeof data / sizeof data[0])), goal);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
