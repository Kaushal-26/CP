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
        int N; cin >> N;

        ROF(k, 1, N + 1) {
                auto t = V<int>(0, 0, 0);
                FOR(i, 1, N + 1) {
                        if(i + k - 1 > N) break;
                        t.push_back({});
                        FOR(j, i, i + k) t.back().push_back(j);
                }

                bitset<1000> ok[N + 1];
                FOR(i, t.size()) {
                        REP(el, t[i]) {
                                ok[el][i] = 1;
                        }
                }
                dbg(t);

                int f = 1;
                FOR(i, 1, N + 1) {
                        FOR(j, 1, N + 1) {
                                if(i == j) continue;
                                if(ok[i] == ok[j]) {
                                        dbg(i, j);
                                        f = 0;
                                }
                        }
                        dbg(ok[i]);
                }

                
                if(!f) continue;

                cout << (int)t.size() << endl;
                REP(i, t) {
                        cout << (int)i.size() << " ";
                        REP(j, i) cout << j << " ";
                        cout << endl;
                }

                bitset<1000> uwu;
                string S; cin >> S;
                FOR(i, S.size()) if(S[i] == '1') uwu[i] = 1;
                FOR(i, 1, N + 1) if(uwu == ok[i]) {
                        cout << i << endl;
                        return;
                }
        }
        assert(0);
}

signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        // cin.tie(0)->sync_with_stdio(0);

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