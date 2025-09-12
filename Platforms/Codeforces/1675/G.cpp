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

// #define int long long

void solve() {
        int N, M; cin >> N >> M;

        vector<int> a(N);
        for(auto &el : a) cin >> el;

        auto dp = vector<vector<vector<int>>>(N + 5, vector<vector<int>>(2 * M + 5, vector<int>(M + 5, -1)));
        auto solve = [&](auto&& solve, int cur, int tot, int last) {
                if(tot < -M || tot > M) return (int)1e9;

                if(cur == N) {
                        if(tot == 0) return 0;
                        return (int)1e9;
                }

                if(dp[cur][tot + M][last] != -1) return dp[cur][tot + M][last];

                int ret = 1e9;

                int val = a[cur] + tot;
                for(int i = last; i >= 0; i--) {
                        ret = min(ret, abs(val - i) + solve(solve, cur + 1, val - i, i));
                }

                return dp[cur][tot + M][last] = ret;
        };

        cout << solve(solve, 0, 0, M) << '\n';
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