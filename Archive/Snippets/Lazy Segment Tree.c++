// https://atcoder.github.io/ac-library/production/document_en/lazysegtree.html
// https://betrue12.hateblo.jp/entry/2020/09/22/194541
// https://betrue12.hateblo.jp/entry/2020/09/23/005940

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

template <class S,
	  S (*op)(S, S),
	  S (*e)(),
	  class F,
	  S (*mapping)(F, S),
	  F (*composition)(F, F),
	  F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
	log = internal::ceil_pow2(_n);
	size = 1 << log;
	d = std::vector<S>(2 * size, e());
	lz = std::vector<F>(size, id());
	for (int i = 0; i < _n; i++) d[size + i] = v[i];
	for (int i = size - 1; i >= 1; i--) {
	    update(i);
	}
    }

    void set(int p, S x) {
	assert(0 <= p && p < _n);
	p += size;
	for (int i = log; i >= 1; i--) push(p >> i);
	d[p] = x;
	for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
	assert(0 <= p && p < _n);
	p += size;
	for (int i = log; i >= 1; i--) push(p >> i);
	return d[p];
    }

    S prod(int l, int r) {
	assert(0 <= l && l <= r && r <= _n);
	if (l == r) return e();

	l += size;
	r += size;

	for (int i = log; i >= 1; i--) {
	    if (((l >> i) << i) != l) push(l >> i);
	    if (((r >> i) << i) != r) push(r >> i);
	}

	S sml = e(), smr = e();
	while (l < r) {
	    if (l & 1) sml = op(sml, d[l++]);
	    if (r & 1) smr = op(d[--r], smr);
	    l >>= 1;
	    r >>= 1;
	}

	return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
	assert(0 <= p && p < _n);
	p += size;
	for (int i = log; i >= 1; i--) push(p >> i);
	d[p] = mapping(f, d[p]);
	for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
	assert(0 <= l && l <= r && r <= _n);
	if (l == r) return;

	l += size;
	r += size;

	for (int i = log; i >= 1; i--) {
	    if (((l >> i) << i) != l) push(l >> i);
	    if (((r >> i) << i) != r) push((r - 1) >> i);
	}

	{
	    int l2 = l, r2 = r;
	    while (l < r) {
		if (l & 1) all_apply(l++, f);
		if (r & 1) all_apply(--r, f);
		l >>= 1;
		r >>= 1;
	    }
	    l = l2;
	    r = r2;
	}

	for (int i = 1; i <= log; i++) {
	    if (((l >> i) << i) != l) update(l >> i);
	    if (((r >> i) << i) != r) update((r - 1) >> i);
	}
    }

    template <bool (*g)(S)> int max_right(int l) {
	return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
	assert(0 <= l && l <= _n);
	assert(g(e()));
	if (l == _n) return _n;
	l += size;
	for (int i = log; i >= 1; i--) push(l >> i);
	S sm = e();
	do {
	    while (l % 2 == 0) l >>= 1;
	    if (!g(op(sm, d[l]))) {
		while (l < size) {
		    push(l);
		    l = (2 * l);
		    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
	return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
	assert(0 <= r && r <= _n);
	assert(g(e()));
	if (r == 0) return 0;
	r += size;
	for (int i = log; i >= 1; i--) push((r - 1) >> i);
	S sm = e();
	do {
	    r--;
	    while (r > 1 && (r % 2)) r >>= 1;
	    if (!g(op(d[r], sm))) {
		while (r < size) {
		    push(r);
		    r = (2 * r + 1);
		    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
	d[k] = mapping(f, d[k]);
	if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
	all_apply(2 * k, lz[k]);
	all_apply(2 * k + 1, lz[k]);
	lz[k] = id();
    }
};

}

using namespace atcoder;

// data, lazy
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n) : array of len n, all elements are e(), 0 to n-1
// lazy_segtree<S, op, e, F, mapping, composition, id> seg(vector<S> v) : array of len n = v.size(), all v
// O(n)
// S(data), F(type on lazy), op(combine data), mapping(lazy -> data), composition(lazy -> lazy), S e() & F id() identity elem & map
// seg.set(int p, S x)       void            : a[p] = x                              O(logn)
// seg.get(int p)             S              : a[p]                                  O(logn)
// seg.prod(int l, int r)     S     [l, r)   : op(a[l], ..., a[r - 1])               O(logn) // l <= r => e()
// seg.all_prod()             S     [0, n)   : seg.prod(0, n)                        O(1)
// seg.apply(int p, F f)     void 		       : a[p] = f(a[p])			  O(logn)
// seg.apply(int l, int r, F f) void [l, r)  : a[i] = f(a[i])			  O(logn)
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

using S = int;
using F = int;

S op(S l, S r) {
}

S e() {}
F id() {}

S mapping(F l, S r) {
}

// f o g first g then f
F composition(F f, F g) {
} 