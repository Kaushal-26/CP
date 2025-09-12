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
        int n; cin >> n;

        int a[n + 1];
        FOR(i, 1, n + 1) cin >> a[i];

        auto b = V<int>(0, n + 1, 32);
        FOR(i, 1, n + 1) {
                b[i] = b[i - 1];
                FOR(j, 32) if(a[i] >> j & 1) b[i][j]++;
        }

        int c[n + 1];
        map<int, vector<int>> ok;
        c[0] = 0;
        FOR(i, 1, n + 1) {
                c[i] = c[i - 1] ^ a[i];
                ok[c[i]].push_back(i);
        }

        int ret = 0;
        FOR(i, 1, n + 1) {
                int L = 0, R = (n - i) / 2, ans = L;
                while(L <= R) {
                        int ew = (L + R) / 2;

                        int mid = i + 2 * ew;
                        
                        auto r = b[mid];
                        FOR(j, 32) r[j] -= b[i - 1][j];

                        int an = 0;
                        FOR(j, 32) if(r[j] == mid - i + 1) an |= 1LL << j;

                        if(an == 0 || an != (c[mid] ^ c[i - 1])) {
                                R = ew - 1;
                        } else {
                                L = ew + 1;
                                ans = ew;
                        }
                }

                dbg(i, ans);
                ret += ans + 1;
                
                L = i + 1, R = n, ans = n + 1;
                while(L <= R) {
                        int mid = (L + R) / 2;
                        
                        auto r = b[mid];
                        FOR(j, 32) r[j] -= b[i - 1][j];

                        int an = 0;
                        FOR(j, 32) if(r[j] == mid - i + 1) an |= 1LL << j;

                        if(an == 0) {
                                ans = mid;
                                R = mid - 1;
                        } else {
                                L = mid + 1;
                        }
                }

                if(ans == n + 1 || ok.find(c[i - 1]) == ok.end()) continue;

                auto it = lower_bound(ok[c[i - 1]].begin(), ok[c[i - 1]].end(), ans) - ok[c[i - 1]].begin();
                it = ok[c[i - 1]].size() - it;
                dbg(i, ans, it);
                ret += it;
        }

        cout << ret << "\n";
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