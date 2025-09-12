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

int n, k, x;
const int N = 2e5 + 100;
int a[N], pf[N];

void solve() {
        cin >> n >> k >> x;

        for(int i = 0; i <= n + 5; i++) a[i] = pf[i] = 0;
        
        for(int i = 1; i <= n; i++) {
                cin >> a[i];
        }

        sort(a + 1, a + 1 + n);

        for(int i = 1; i <= n; i++) {
                pf[i] = pf[i - 1] + a[i];        
        }

        int ans = -1e18, S = pf[n];
        for(int i = n, j = 0; i >= 0 && j <= k; i--, j++) {
                int A = pf[n] - pf[i];
                int B = pf[i] - pf[max(0LL, i - x)];
                clog << dbg(i) << dbg(A) << dbg(B) << '\n';
                ans = max(ans, S - A - 2 * B);
        }

        cout << ans << '\n';
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