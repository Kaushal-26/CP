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
        int n, a, b; cin >> n >> a >> b;

        vector<int> x(n);
        for(auto &el : x) cin >> el;

        int sum = accumulate(x.begin(), x.end(), 0LL);

        int ans = b * sum;
        for(int i = 0; i < n; i++) {
                clog << prs(a, b, i, x[i]) << db( a * x[i] + b * (sum - (n - i) * x[i])) << endl;
                ans = min(ans, a * x[i] + b * (sum - (n - i) * x[i]) + b * x[i]);
                sum -= x[i];
        }

        cout << ans << '\n';
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