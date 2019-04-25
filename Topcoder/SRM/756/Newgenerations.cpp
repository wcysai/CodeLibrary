#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
map<pair<int,int>,int > mp;
int dp[2][(1<<20)];
class Newgenerations {
	public:
    int n,m,tot,cnt;
    int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
    vector<int> G[MAXN];
    void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
    int find_id(int x,int y)
    {
        if(mp.find(P(x,y))==mp.end()) mp[P(x,y)]=tot++;
        return mp[P(x,y)];
    }
	int count(vector <string> field) {
        mp.clear();
		n=field.size(); m=field[0].size();
        for(int i=0;i<n*m;i++) G[i].clear();
        tot=0; cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(field[i][j]=='X')
                {
                    bool valid=false;
                    vector<int> edges; edges.clear();
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+dx[k],ny=j+dy[k];
                        if(nx<0||nx>=n||ny<0||ny>=m) 
                        {
                            valid=true;
                            continue;
                        }
                        assert(field[nx][ny]=='.');
                        if(field[nx][ny]=='.')
                        {
                            valid=true;
                            continue;
                        }
                        else if(field[nx][ny]=='*')
                        {
                            int id=find_id(nx,ny);
                            edges.push_back(id);
                        }
                    }
                    if(!valid)
                    {
                        if(!edges.size()) return 0;
                        for(int i=0;i<(int)edges.size();i++) G[edges[i]].push_back(cnt);
                        cnt++;
                    }
                }
            }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=0;i<tot;i++)
        {
            int now=i&1,nxt=now^1;
            memset(dp[nxt],0,sizeof(dp[nxt]));
            int curmask=0;
            for(auto to:G[i]) curmask|=(1<<to);
            for(int mask=0;mask<(1<<cnt);mask++)
            {
                if(!dp[now][mask]) continue;
                add(dp[nxt][mask],dp[now][mask]);
                add(dp[nxt][mask|curmask],dp[now][mask]);
            }
        }
        return dp[tot&1][(1<<cnt)-1];
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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			string field[]            = {"x*"
,"*#"};
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = Newgenerations().count(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string field[]            = {"##."
,".#."
,".##"}
;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = Newgenerations().count(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string field[]            = {"#.......#.......#"
,"##.....###.....##"
,"###...#####...###"
,"####.x#####x.####"
,"####xxx###xxx####"
,"###xx*******xx###"
,"##x***********x##"
,"#***************#"
            }
;
			int expected__            = 134217728;

			std::clock_t start__      = std::clock();
			int received__            = Newgenerations().count(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string field[]            = {"#****#*#*****#******"
,"#****#..*.#*#*.*x.#*"
,"****#**#**##*****#**"
,"*##***#*##x*x***#x*x"
,"****#*#*****#*****#*"
,".**###*#**x*.*###**x"
,"*#**##*.**#****x**.*"
,"#************.***#**"
,"*******#*#****#***.*"
,"*#.***##**.**##.#*##"
,"*.##****.****#.****x"
,"*.*#****#*##*#***.#*"
,"###x#*.***#x***#***#"
,"#*.**#**#*******#.**"
,"****#x***##x*.##.*#*"
,"*###*###****.**#****"
,"*.*#*****###****##**"
,"*#*#**.*#*x*##**#***"
,"*##*******#x#**#****"
,"***##*******#*******"}
;
			int expected__            = 961436185;

			std::clock_t start__      = std::clock();
			int received__            = Newgenerations().count(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string field[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Newgenerations().count(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string field[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Newgenerations().count(vector <string>(field, field + (sizeof field / sizeof field[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string field[]            = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = Newgenerations().count(vector <string>(field, field + (sizeof field / sizeof field[0])));
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
