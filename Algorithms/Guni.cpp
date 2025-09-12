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

int timer;
const int N = 1e5 + 5;
int tin[N], tout[N], sz[N], height[N], tidx[N];

int C[N];
map<int, int> cnt[N];

int n, m, max_height = -1;
vector<int> g[N];
vector<array<int, 2>> Q[N];

int ans[N];

void DFS(int cur, int p = 0) {
        ckmax(max_height, height[cur]);
        tin[cur] = ++timer;
        tidx[timer] = cur;
        sz[cur] = 1;
        REP(v, g[cur]) if(v != p) {
                height[v] = height[cur] + 1;
                DFS(v, cur);
                sz[cur] += sz[v];
        }
        tout[cur] = timer;
}

void add(int H, int ch) {
        cnt[H][ch] ++;
}
void del(int H, int ch) {
        cnt[H][ch] --;
        if(cnt[H][ch] == 0) cnt[H].erase(ch);
}

void dfs(int cur, int p = 0, bool keep = 0) {
        int bigChild = -1;
        REP(v, g[cur]) {
                if(bigChild == -1 || sz[bigChild] < sz[v]) bigChild = v;
        }

        REP(v, g[cur]) if(v != bigChild) {
                dfs(v, cur, 0);
        } 

        if(bigChild != -1) dfs(bigChild, cur, 1);

        REP(v, g[cur]) if(v != bigChild) {
                FOR(i, tin[v], tout[v] + 1) add(height[tidx[i]], C[tidx[i]]);
        }

        add(height[cur], C[cur]);

        // Here
        REP(i, Q[cur]) if(i[0] + height[cur] <= max_height) ans[i[1]] = cnt[i[0] + height[cur]].size();

        if(!keep) {
                FOR(i, tin[cur], tout[cur] + 1) del(height[tidx[i]], C[tidx[i]]);
        }
}

void solve() {
        cin >> n;

        auto parents = V<int>(0, 0);

        map<string, vector<int>> hash;
        FOR(i, n) {
                string s; cin >> s;
                int P; cin >> P;
                hash[s].push_back(i + 1);
                if(P == 0) {
                        parents.push_back(i + 1);
                        continue;
                }
                g[P].push_back(i + 1);
        }

        int ew = 0;
        REP(i, hash) {
                REP(j, i.second) {
                        C[j] = ew;
                }
                ew++;
        }

        cin >> m;

        FOR(i, m) {
                int V, H; cin >> V >> H;
                Q[V].push_back({H, i});
        }

        REP(i, parents) {
                if(height[i] == 0) {
                        height[i] = 1;
                        max_height = -1;
                        DFS(i);
                        dfs(i);
                }
        }

        FOR(i, m) cout << ans[i] << "\n";
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