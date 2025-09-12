#ifdef Kaushal_26
        #include <debug.h>
#else
        #include <bits/stdc++.h>

        using namespace std;

        #define clog            if (0) cerr
        #define lvl(...)        if (0) cerr
        #define dbg(...)        42
#endif

// #define int long long

int n;
const int N = 2e5 + 100;
int a[N];

auto gcd2 = []<std::integral T>(T a, T b) -> T {
    while (b) {
        a = std::exchange(b, a % b);
    }
    return std::abs(a);
};

void solve() {
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];

        int ret = 0;
        for(int i = 1; i <= n; i++) if(n % i == 0) {
                int g = 0;
                for(int j = 0; j < n; j += i) {
                        for(int k = 0; k < i; k++) {
                                g = gcd2(g, abs(a[k] - a[j + k]));
                        }
                }
                ret += g != 1;
        }

        cout << ret << '\n';
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


auto gcd2 = []<std::integral T>(T a, T b) -> T {
    while (b) {
        a = std::exchange(b, a % b);
    }
    return std::abs(a);
};