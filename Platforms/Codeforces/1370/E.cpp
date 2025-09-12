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

int n;
string s, t;

void solve() {
        cin >> n;
        cin >> s >> t;

        {
                string ns = s, nt = t;
                ranges::sort(ns);
                ranges::sort(nt);
                if(ns != nt) {
                        cout << "-1\n";
                        return;
                }
        }

        int ans = 0;
        int O = 0, Z = 0;
        for(int i = 0; i < n; i++) {
                if(s[i] != t[i]) {
                        if(s[i] == '0') {
                                Z++;
                                O = max(0LL, O - 1);
                        } else {
                                O++;
                                Z = max(0LL, Z - 1);
                        }
                        ans = max(ans, O + Z);
                }
        }

        cout << ans << '\n';

        // vector<set<int>> S(2);
        // for(int i = 0; i < n; i++) {
        //         if(s[i] != t[i]) {
        //                 S[s[i] - '0'].insert(i);
        //         }
        // }

        // n = S[0].size() + S[1].size();
        // int ans = 0;
        // while(n > 0) {
        //         if(*S[0].begin() > *S[1].begin()) swap(S[0], S[1]);

        //         clog << db(S[0]) << db(S[1]) << endl;

        //         int st = 0, id = -1, cnt = 0;
        //         while(1) {
        //                 auto it = S[st].lower_bound(id);
        //                 if(it == S[st].end()) break;
        //                 id = *it;
        //                 S[st].erase(it);
        //                 st ^= 1;
        //                 cnt++;
        //         }

        //         if(cnt % 2) S[st ^ 1].insert(id), cnt--;
                
        //         ans++;
        //         n -= cnt;
        // }

        // cout << ans << '\n';
}
 
signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        cin.tie(0) -> sync_with_stdio(0);
        
        int T = 1; // cin >> T;
        for(int i = 1; i <= T; i++) {
                clog << '\n' << "\033[36m" << string(100, '-') <<  "\033[39m" << '\n' << '\n';
                solve();
                if(i == T) clog << '\n' << "\033[36m" << string(100, '-') <<  "\033[39m";
        }

        #ifdef Kaushal_26
                auto end = std::chrono::high_resolution_clock::now();
                clog << fixed << setprecision(9);
                clog << "\n\n\033[35mExecution time: \033[31m" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-9 << "\033[34m seconds\033[39m." << endl;
        #endif
}
 
// 1.77245