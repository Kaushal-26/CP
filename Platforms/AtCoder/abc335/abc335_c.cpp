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
        int N, Q; cin >> N >> Q;

        vector<vector<pair<int, int>>> ops(N);

        deque<array<int, 2>> a;
        int x = 1, y = 0, done = 0;
        // a.push_back({x, y});
        for(int i = 0; i < Q; i++) {
                int t; cin >> t;
                if(t == 1) {
                        char c; cin >> c;
                        if(c == 'U') y++;
                        else if(c == 'D') y--;
                        else if(c == 'R') x++;
                        else x--;
                        done++;
                a.push_back({x, y});
                } else {
                        cin >> t; --t;
                        ops[t].push_back({done, i});
                }
        }

        int mx = -1e18;
        vector<array<int, 2>> ans(Q, {mx, mx});
        for(int i = 0; i < N; i++) {
                a.push_front({i + 1, 0});
                for(auto &el : ops[i]) {
                        ans[el.second] = a[el.first];
                }
                clog << db(a) << endl;
                clog << db(ops[i]) << endl;
                a.pop_back();
        }

        clog << db(ans) << endl;

        for(int i = 0; i < Q; i++) {
                if(ans[i][0] == mx) continue;
                cout << ans[i][0] << ' ' << ans[i][1] << '\n';
        }
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
                clog << "\n\n\033[35mExecution time: \033[31m" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-9 << "\033[34m seconds\033[39m." << '\n' << '\n';
        #endif
}
 
// 1.77245