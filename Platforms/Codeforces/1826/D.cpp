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

// https://atcoder.github.io/ac-library/production/document_en/segtree.html
namespace atcoder {

namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  

using namespace atcoder;

// segtree<S, op, e> seg(int n)                    : array of len n, all elements are e(), 0 to n-1
// segtree<S, op, e> seg(vector<S> v)              : array of len n = v.size(), all v
// O(n)      
// S : type,               op : binary operation or merge function ... S op(S a, S b),             S e() identity element
// For RMQ => S : int, op : int op(int a, int b) {return min(a, b);}, e : int e() {return (int)1e9}

// seg.set(int p, S x)       void            : a[p] = x                              O(logn)
// seg.get(int p)             S              : a[p]                                  O(logn)
// seg.prod(int l, int r)     S     [l, r)   : op(a[l], ..., a[r - 1])               O(logn) // l <= r => e()
// seg.all_prod()             S     [0, n)   : seg.prod(0, n)                        O(1)

// seg.max_right<f>(int l)   int             : takes f function applies binary search on it. bool f(S x), seg.max_right<F>(int l, F f) // your fxn
// // r = l or f(op(a[l], ..., a[r-1])) = true     O(logn)
// // r = n or f(op(a[l], ..., a[r])) = false
// // f is monotone, this is maximum r for f(op(a[l], ..., a[r-1])) = true
// // Constraints: f(e()) = true, 0 <= l <= n
// seg.min_left<f>(int r)    int             : same as max_right
// // l = r or f(op(a[l], ..., a[r-1])) = true
// // r = 0 or .... = false
// // f is monotone, this is minimum l for f(op(a[l], ..., a[r-1])) = true
// // Constraints: f(e()) = true, 0 <= r <= n

#define int long long

int n;
const int N = 1e5 + 5;
int a[N];

struct S {
        int ans, val, idx_val;
};

S op(S L, S R) {
        if(L.ans == -1) return R;
        if(R.ans == -1) return L;
        return {max({L.ans, R.ans, L.idx_val + R.val}), max(L.val, R.val), max(L.idx_val, R.idx_val)};
}

S e() {return {-1, -1, -1};}

void solve() {
        cin >> n;

        vector<S> b(n);
        for(int i = 0; i < n; i++) {
                cin >> a[i];
                b[i] = {0, a[i], a[i] + i};
        }

        int ans = 0;
        segtree<S, op, e> seg(b);
        for(int i = 2; i < n; i++) {
                ans = max(ans, a[i] - i + seg.prod(0, i).ans);
        }

        cout << ans << '\n';
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