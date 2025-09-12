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
        int n, c, q; cin >> n >> c >> q;

        string s; cin >> s;

        auto L = V<int>(0, 0);
        L.push_back(n);
        auto t = V<array<int, 2>>({0, 0}, c + 1);
        FOR(i, c) {
                int l, r; cin >> l >> r; -- l, -- r;
                L.push_back(L.back() + r - l + 1);
                t[i + 1] = {l, r};
        }

        int C = L.size();
        auto x = V<array<int, 2>>({0, 0}, C, 0);
        FOR(i, q) {
                int k; cin >> k; --k;
                int j = C - 1;
                ROF(i, C) {
                        if(L[i] > k)  {
                                j = i;
                        }
                }
                x[j].push_back({i, k});
        }

        dbg(x);

        ROF(i, 1, C) {
                REP(el, x[i]) {
                        el[1] -= L[i - 1];
                        el[1] += t[i][0];

                        int k = i - 1;
                        ROF(j, i) {
                                if(L[j] > el[1]) {
                                        k = j;
                                }
                        }
                        x[k].push_back(el);
                }
                dbg(x);
        }

        dbg(n, c, q, s, L, x[0]);

        auto ans = V<char>(0, q);
        REP(i, x[0]) ans[i[0]] = s[i[1]];

        FOR(i, q) cout << ans[i] << "\n";
}

signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        cin.tie(0)->sync_with_stdio(0);

        int TestCases = 1; cin >> TestCases;
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