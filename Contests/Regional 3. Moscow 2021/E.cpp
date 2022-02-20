#include <bits/stdc++.h>
using namespace std;

void debug_out() {cerr << endl;}
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T)
{
    cerr << " " << H;
    debug_out(T...);
}
#ifndef ONLINE_JUDGE
    #define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
#else
    #define debug(...) 42
#endif

int T;
using ll = long long;
ll n;
string s;

void check(){
    for (ll i = 9099999999; i <= 9099999999; i += 1) {
        vector<int> a;
        ll cur = i;
        while(cur) {
            a.emplace_back(cur % 10);
            cur /= 10;
        }
        sort(a.begin(), a.end());
        ll g = 0;
        int cnt = 0;
        do{
            ll now = 0;
            for (auto x : a) {
                now = now * 10 + x;
            }
            g = __gcd(g, now);
            cout << now << " " << now % 81 << "\n";
            cnt += 1;
        }while(next_permutation(a.begin(), a.end()));
        //if(cnt == 1) continue;
        if(g) {
            cout << i << " " << cnt << " " << g << "\n";
            return;
        }
    }
}






int main(){
    printf("%d\n",__gcd(__gcd(5055,5505),__gcd(5550,555)));
    //check();
    cin >> T;
    while(T--) {
        cin >> s;
        n = 0;
        assert(s[0] != '0');
        {
            int ok = 1;
            for (int i = 1; i < s.size(); i += 1) {
                if(s[i] == s[i - 1]) continue;
                ok = 0;
                break;
            }
            if(ok) {
                cout << s << "\n";
                continue;
            }
        }
        for (auto c : s) {
            n = n * 10 + c - '0';
        }
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        if(n < 10) {
            cout << n << "\n";
            continue;
        }
        while(n % 2 == 0) {
            c2 += 1;
            n /= 2;
        } 
        while(n % 3 == 0) {
            c3 += 1;
            n /= 3;
        }
        while(n % 5 == 0) {
            c5 += 1;
            n /= 5;
        }
        while(n % 7 == 0) {
            c7 += 1;
            n /= 7;
        }
        if(n > 1) {
            cout << "-1\n";
            continue;
        }
        if(c5 + c7 > 0) {
            if((c5 and c7) or (c5 + c7 >= 2)) cout << "-1\n";
            else{
                if(c2) {
                    cout << "-1\n";
                } 
                else{
                    if(c3 > 2) cout << "-1\n";
                    else if(c3 == 2) {
                        cout << (c5 ? 5 : 7);
                        cout << 0; 
                        for (int i = 1; i < 9; i += 1) {
                            cout << (c5 ? 5 : 7);
                        }
                        cout << "\n";
                    }
                    else if(c3 == 1) {
                        cout << (c5 ? 5 : 7);
                        cout << 0;  
                        for (int i = 1; i < 3; i += 1) {
                            cout << (c5 ? 5 : 7);
                        }
                        cout << "\n";
                    }
                    else{
                        cout << s << "\n";
                    }
                }
            }
        }
        else{
            if(c3 == 0) {
                if(c2 > 3) cout << "-1\n";
                else{
                    int cur = 1;
                    for (int i = 0; i < c2; i += 1) {
                        cur *= 2;
                    }
                    cout << cur << "\n";
                }
            }
            else if(c2 == 0) {
                if(c3 > 4) cout << "-1\n";
                else if(c3 == 4) {
                    cout << "9099999999\n";
                }
                else if(c3 == 3) {
                    cout << 3699 << "\n";
                }
                else if(c3 == 2) {
                    cout << 9 << "\n";
                }
                else if(c3 == 1) {
                    cout << 3 << "\n";
                }
                else{
                    cout << "1\n";
                }
            }
            else{
                if(c3 == 3 and c2 == 1) {
                    cout << "6066666666\n";
                }
                
                else if(c3 == 2 and c2 == 3) {
                    cout << "8088888888\n";
                }
                else if(c3 == 2 and c2 == 2) {
                    cout << "48888\n";
                }
                else if(c3 == 2 and c2 == 1) {
                    cout << "288\n";
                }
                else if(c3 == 1 and c2 == 3) {
                    cout << "8088\n";
                } 
                else if(c3 == 1 and c2 == 2) {
                    cout << "48\n";
                }
                else if(c3 == 1 and c2 == 1) {
                    cout << "6\n";
                }
                else cout << "-1\n";
            }
        }
    }
    return 0;
}
