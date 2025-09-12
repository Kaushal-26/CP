#ifdef Kaushal_26
        #include <debug.h>
#else
        #include <bits/stdc++.h>

        using namespace std;

        #define clog                    if (0) cerr
        #define lvl(...)                42
        #define dbg(...)                42
#endif

#define int                             long long

#define overload5(a, b, c, d, e, ...)   e
#define FORS(i, a, b, c)                for(int i = (a); i < (int)(b); i += c)
#define FOR1(i, a, b)                   for(int i = (a); i < (int)(b); ++i)
#define F0R(i, a)                       for(int i = (0); i < (int)(a); ++i)
#define ROFS(i, a, b, c)                for(int i = (b) - 1; i >= (int)(a); i -= c)
#define ROF1(i, a, b)                   for(int i = (b) - 1; i >= (int)(a); --i)
#define R0F(i, a)                       for(int i = (a) - 1; i >= (int)(0); --i)
#define FOR(...)                        overload5(__VA_ARGS__, FORS, FOR1, F0R)(__VA_ARGS__)
#define ROF(...)                        overload5(__VA_ARGS__, ROFS, ROF1, R0F)(__VA_ARGS__)
#define REP(i, x)			for(auto &i : x)

template <class T> auto V(const T& value, int size) {
        return vector<T>(size, value);
}

template <class T, class... D> auto V(const T& value, int size, D... w) {
        auto W = V(value, w...);
        return vector<decltype(W)>(size, W);
}

template <class T> bool ckmin(T &a, const T b) {
        return b < a ? a = b, 1 : 0;
}

template<class T> bool ckmax(T &a, const T b) {
        return b > a ? a = b, 1 : 0;
}

void solve() {
        int H, W, K; cin >> H >> W >> K;

        auto a = V<int>(0, H + 1, W + 1), b = a;
        FOR(i, H) FOR(j, W) {
                char c; cin >> c;
                if(c == '.') {
                        a[i + 1][j + 1] = 1;
                } else if(c == 'x') {
                        b[i + 1][j + 1] = 1;
                } else {
                        a[i + 1][j + 1] = 0;
                }
        }

        auto ph = b, pv = b, h = a, v = a;
        FOR(i, 1, H + 1) FOR(j, 1, W + 1) {
                ph[i][j] += ph[i][j - 1];
                if(b[i][j] || b[i][j - 1]) continue;
                h[i][j] += h[i][j - 1];
        }
        FOR(j, 1, W + 1) FOR(i, 1, H + 1) {
                pv[i][j] += pv[i - 1][j];
                if(b[i][j] || b[i - 1][j]) continue;
                v[i][j] += v[i - 1][j];
        }

        dbg(a, v, h, pv, ph);

        int ans = 1e18;
        FOR(i, 1, H + 1) FOR(j, K, W + 1) {
                if(ph[i][j] - ph[i][j - K] == 0) {
                        ckmin(ans, h[i][j] - h[i][j - K]);
                }
        }
        FOR(j, 1, W + 1) FOR(i, K, H + 1) {
                if(pv[i][j] - pv[i - K][j] == 0) {
                        ckmin(ans, v[i][j] - v[i - K][j]);
                }
        }

        if(ans == 1e18) ans = -1;

        cout << ans << "\n";

}

signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        cin.tie(0)->sync_with_stdio(0);

        int TestCases = 1; // cin >> TestCases;
        for(int TestCase = 1; TestCase <= TestCases; TestCase++) {
                clog << "\n"; dbg(TestCase);
                solve();
        }

        #ifdef Kaushal_26
                auto end = std::chrono::high_resolution_clock::now();
                clog << fixed << setprecision(15) << "\n";
                auto Execution_Time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-9;
                dbg(Execution_Time);
        #endif
        return 0;
}

// 1.77245