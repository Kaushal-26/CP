#ifdef Kaushal_26
        #include <debug.h>
#else
        #include <bits/stdc++.h>

        using namespace std;

        #define clog            if (0) cerr
        #define lvl(...)        if (0) cerr
        #define dbg(...)        42
#endif

#define int long long

int n, q, s, d, k;
const int N = 100100, BLK = 350;
int a[N];
int dp[N][BLK], sum[N][BLK];

void solve() {
        cin >> n >> q;

        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = n - 1; i >= 0; i--) {
                for(int j = 1; j < BLK; j++) {
                        dp[i][j] = sum[i][j] = a[i];
                        if(i + j < n) {
                                dp[i][j] += dp[i + j][j] + sum[i + j][j];
                                sum[i][j] += sum[i + j][j];
                        }
                }
        }

        for(int _ = 1, ans = 0; _ <= q; _++) {
                cin >> s >> d >> k; --s;
                ans = 0;
                if(d < BLK) {
                        ans = dp[s][d];
                        if(s + d * k < n) {
                                ans -= dp[s + d * k][d] + (sum[s + d * k][d] * k);
                        }
                } else {
                        for(int i = s; i < s + d * k; i += d) {
                                ans += (int)a[i] * ((i - s) / d + 1);
                        }
                }
                cout << ans << ' ';
        }

        cout << '\n';
}
 
signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        cin.tie(0)->sync_with_stdio(0);
        
        int T = 1; cin >> T;
        for(int i = 1; i <= T; i++) {
                clog << '\n' << "\033[36m" << string(100, '-') <<  "\033[39m" << '\n' << '\n';
                solve();
                if(i == T) clog << '\n' << "\033[36m" << string(100, '-') << "\033[39m";
        }

        #ifdef Kaushal_26
                auto end = std::chrono::high_resolution_clock::now();
                clog << fixed << setprecision(15);
                clog << "\n\n\033[35mExecution time: \033[31m" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-15 << "\033[34m seconds\033[39m." << '\n' << '\n';
        #endif
        return 0;
}
 
// 1.77245