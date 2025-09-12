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
        int n, m; cin >> n >> m;

        auto g = V<array<int, 2>>({0, 0}, n, 0);
        FOR(i, m) {
                int u, v, w; cin >> u >> v >> w; -- u, -- v;
                g[u].push_back({v, w});
                g[v].push_back({u, w});
        }

        auto ok = V<int>(-1, n);
        REP(i, g[n - 1]) ok[i[0]] = i[1];

        auto print = V<int>(1, n);
        print[n - 1] = 0;

        auto v = V<int>(0, 0);
        FOR(i, n - 1) if(ok[i] != -1) {
                v.push_back(i);
        }

        dbg(ok, v, print);

        if((int)v.size() == 0) {
                cout << "inf\n";
                return;
        }

        auto ans = V<int>(0, 0, 0);
        auto time = V<int>(0, 0);
        int ret = 0;
        while(v.size() > 0) {
                ranges::sort(v, [&](auto &P, auto &Q) {
                        if(ok[P] > ok[Q]) return 1;
                        return 0;
                });

                auto el = v.back();
                v.pop_back();

                ret += ok[el];
                time.push_back(ok[el]);

                REP(i, v) ok[i] -= ok[el];

                ans.push_back(print);
                print[el] = 0;

                REP(i, g[el]) {
                        if(i[0] == n - 1) continue;
                        if(ok[i[0]] == -1) {
                                ok[i[0]] = i[1];
                                v.push_back(i[0]);
                        } else {
                                ckmin(ok[i[0]], i[1]);
                        }
                }

                if(el == 0) break;

                if((int)ans.size() == n * n) break;

                dbg(el, ret, ok, v, print);
        }

        dbg(time, ans, ret, ok);

        if(ok[0] == -1) {
                cout << "inf\n";
                return;
        }
        
        cout << ret << " " << (int)ans.size() << "\n";
        FOR(i, ans.size()) {
                REP(el, ans[i]) cout << el;
                cout << " " << time[i] << "\n";
        }
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