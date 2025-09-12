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

int n, k, x, y, add;
const int N = 2e5 + 5;
vector<int> g[N];
int dp[N], a[N], cnt[N], f[N];

void dfs(int cur, int p = -1, int up = 0) {
        if(cur == y) {
                add = up;
                f[cur] = 1;
                return;
        }

        for(auto &v : g[cur]) if(v != p) {
                dfs(v, cur, up + 1);
                f[cur] |= f[v];
        }
}

void DFS(int cur, int p = -1, int up = 0) {
        for(auto &v : g[cur]) if(v != p) {
                DFS(v, cur, f[v] ? 0 : (up + 1));
                if(f[v]) continue;
                dp[cur] += dp[v] + 2 * a[v];
                a[cur] |= a[v];
        }
}

void solve() {
        cin >> n >> k;

        cin >> x >> y; -- x, -- y;

        for(int i = 0, u; i < k; i++) {
                cin >> u; -- u;
                a[u] = 1;
        }

        for(int i = 0, u, v; i < n - 1; i++) {
                cin >> u >> v; -- u, -- v;
                g[u].push_back(v);
                g[v].push_back(u);
        }

        dfs(x);

        int ans = 0;
        DFS(x);

        for(int i = 0; i < n; i++) clog << prs(i, a[i], dp[i], cnt[i], f[i]) << endl;

        for(int i = 0; i < n; i++) if(f[i]) ans += dp[i];

        cout << ans + add << '\n';

        add = 0;
        for(int i = 0; i < n; i++) {
                g[i].clear();
                dp[i] = a[i] = f[i] = cnt[i] = 0;
        }
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