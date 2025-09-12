#ifdef Kaushal_26
        #include <debug.h>
#else
        #include <bits/stdc++.h>

        using namespace std;

        #define clog if (0) cerr
        #define DB(...) if(0) 42
        #define db(...) 42
        #define pr(...) 42
        #define prs(...) 42
#endif

#define int long long

void solve() {
        int n, k; cin >> n >> k;

        string s; cin >> s;

        vector<int> f(26, -1);
        for(int i = 0; i < n; i++) {
                if(f[s[i] - 'a'] != -1) {
                        s[i] = f[s[i] - 'a'] + 'a';
                } else if(k > 0) {
                        int j = s[i] - 'a';
                        for(j = s[i] - 'a'; j > 0; j--) {
                                if(f[j] != -1) {
                                        j = f[j];
                                        break;
                                }
                                if(k > 0) {
                                        k--;
                                } else {
                                        break;
                                }
                        }
                        int ok = j;
                        for(; j <= s[i] - 'a'; j++) {
                                f[j] = ok;
                        }
                        s[i] = ok + 'a';
                }
                clog << db(f) << db(k) << endl;
        }

        cout << s << '\n';
}
 
signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        cin.tie(0) -> sync_with_stdio(0);
        
        int T = 1; cin >> T;
        for(int i = 1; i <= T; i++) {
                clog << '\n' << "\033[36m" << string(100, '-') <<  "\033[39m" << '\n' << '\n';
                solve();
                if(i == T) clog << '\n' << "\033[36m" << string(100, '-') <<  "\033[39m";
        }

        #ifdef Kaushal_26
                auto end = std::chrono::high_resolution_clock::now();
                clog << fixed << setprecision(9);
                clog << "\n\n\033[35mExecution time: \033[31m" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-9 << "\033[34m seconds\033[39m." << '\n' << '\n';
        #endif
}
 
// 1.77245