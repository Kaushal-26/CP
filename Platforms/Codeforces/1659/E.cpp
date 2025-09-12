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

// https://atcoder.github.io/ac-library/production/document_en/dsu.html

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}

using namespace atcoder;

// dsu d(n)                 : dsu of n vertices 0 to n-1                   O(n)
// d.merge(a, b)    int     : connect, and returns parent                  O(a(n))
// d.same(a, b)     bool    : isconnected                                  O(a(n))
// d.leader(a)      int     : parent of a                                  O(a(n))
// d.size(a)        int     : size of component                            O(a(n))    
// d.groups()       vi<vi>  : ist of the vertices in a connected compo     O(n)

#define int long long

int n, m, q;
const int N = 100100;
vector<array<int, 2>> g[N], Q(N);

void solve() {
        cin >> n >> m;

        for(int i = 0, u, v, w; i < m; i++) {
                cin >> u >> v >> w; --u, --v;
                g[u].push_back({v, w});
                g[v].push_back({u, w});
        }

        cin >> q;
        for(int i = 0, u, v; i < q; i++) {
                cin >> u >> v; --u, --v;
                Q[i] = {u, v};
        }

        vector<dsu> ok(30), ko(30);
        for(int i = 0; i < 30; i++) ko[i] = ok[i] = dsu(n + 1);

        for(int i = 0; i < n; i++) {
                for(auto &[v, w] : g[i]) {
                        for(int j = 0; j < 30; j++) {
                                if(w >> j & 1) {
                                        ok[j].merge(i, v);
                                        ko[j].merge(i, v);
                                }
                        }
                }
        }

        for(int i = 0; i < n; i++) {
                for(auto &[v, w] : g[i]) {
                        if(w % 2 == 0) {
                                for(int j = 0; j < 30; j++) {
                                        ko[j].merge(i, n);
                                        ko[j].merge(v, n);
                                }
                        }
                }
        }

        for(int i = 0; i < q; i++) {
                int ret = 2;
                for(int j = 0; j < 30; j++) {
                        if(ok[j].same(Q[i][0], Q[i][1])) {
                                ret = min(ret, 0LL);    
                        }
                        if(j && ko[j].same(Q[i][0], n)) {
                                ret = min(ret, 1LL);
                        }
                }
                cout << ret << '\n';
        }
}
 
signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        cin.tie(0) -> sync_with_stdio(0);
        
        int T = 1; // cin >> T;
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