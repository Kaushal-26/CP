#ifdef Kaushal_26
        #include <debug.h>
#else
        #include <bits/stdc++.h>

        using namespace std;

        #define clog            if (0) cerr
        #define lvl(...)        if (0) cerr
        #define dbg(...)        42
#endif

#define int long long

#define overload4(a, b, c, d, e, ...) e
#define overload3(a, b, c, d, ...) d
 
#define FOR2(i, a) for (int i = 0; i <= (int)(a); i++)
#define FOR3(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define FOR4(i, a, b, c) for (int i = (int)(a); i < (int)(b); i += (int)(c))
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2)(__VA_ARGS__)

void solve() {
        int n; cin >> n;

        cout << n << endl;

        lvl();

        int a[n];
        FOR(i, a) cin >> a[i];

        // int n; cin >> n;

        // set<int> dont;
        // int mn = 0, mx = 1e18;
        // for(int i = 0, t, x; i < n; i++) {
        //         cin >> t >> x;
        //         if(t == 1) {
        //                 mn = max(mn, x);
        //         } else if(t == 2) {
        //                 mx = min(mx, x);
        //         } else {
        //                 dont.insert(x);
        //         }
        // }

        // set<int> s;     
        // for(auto &el : dont) {
        //         if(el >= mn && el <= mx) {
        //                 s.insert(el);
        //         }
        // }
        
        // clog << dbg(mn) << dbg(mx) << dbg(s) << '\n';

        // cout << max(0LL, mx - mn + 1 - (int)s.size()) << '\n';
}
 
signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        cin.tie(0)->sync_with_stdio(0);
        
        int T = 1; cin >> T;
        for(int i = 1; i <= T; i++) {
                clog << '\n' << "\033[36m" << string(100, '-') <<  "\033[39m" << '\n' << '\n';
                solve();
                if(i == T) clog << '\n' << "\033[36m" << string(100, '-') << "\033[39m";
        }

        #ifdef Kaushal_26
                auto end = std::chrono::high_resolution_clock::now();
                clog << fixed << setprecision(15);
                clog << "\n\n\033[35mExecution time: \033[31m" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-15 << "\033[34m seconds\033[39m." << '\n' << '\n';
        #endif
        return 0;
}
 
// 1.77245

// #include <bits/stdc++.h>

// using namespace std;

// // #include <ext/pb_ds/assoc_container.hpp>
// // #include <ext/pb_ds/tree_policy.hpp>

// // using namespace __gnu_pbds;

// #define pb                      	push_back
// #define nl				"\n"
// #define sp 				" "
// #define all(x)                  	(x).begin(), (x).end()
// #define sz(x)				(int)(x).size()
// #define deci(x)			        fixed << setprecision(x)
// #define set(a, x)			memset(a, x, sizeof a)
// #define dedup(a)			a.erase(unique(all(a)), a.end())

// #define overload(a, b, c, d, e, ...)    e
// #define rep(i, x)			for(auto &i : x)
// #define FORS(i, a, b, c)                for(int i = (a); i < (int)(b); i += c)
// #define FOR1(i, a, b)                   for(int i = (a); i < (int)(b); ++i)
// #define F0R(i, a)                       for(int i = (0); i < (int)(a); ++i)
// #define ROFS(i, a, b, c)                for(int i = (b) - 1; i >= (int)(a); i -= c)
// #define ROF1(i, a, b)                   for(int i = (b) - 1; i >= (int)(a); --i)
// #define R0F(i, a)                       for(int i = (a) - 1; i >= (int)(0); --i)
// #define FOR(...)                        overload(__VA_ARGS__, FORS, FOR1, F0R)(__VA_ARGS__)
// #define ROF(...)                        overload(__VA_ARGS__, ROFS, ROF1, R0F)(__VA_ARGS__)
            
// // template<typename T, typename compare = less<T>>
// // using oset                        = tree<T, null_type, compare, rb_tree_tag, tree_order_statistics_node_update>;

// // For Printing Containers.     https://quangloc99.github.io/2021/07/30/my-CP-debugging-template.html
// template <class container, class = decltype(begin(declval<container>()))> 
// typename enable_if<!is_same<container, string>::value, ostream&>::type
// operator<< (ostream& out, const container& con) {
//         for(auto it = con.begin(), ti = con.begin(); it != con.end(); it++) {
//                 ti++;
//                 out << *it << " "[ti == con.end()];
//         }
//         return out;
// }
// template<class... T>
// void print(const T&... t) {
//         (..., (cout << (t) << sp));
//         cout << nl;
// }

// template <class T> auto V(const T& value, int size) {
//         return vector<T>(size, value);
// }
// template <class T, class... D> auto v(const T& value, int size, D... w) {
//         return vector<decltype(V(value, w...))>(size, V(value, w...));
// }

// template <class T> using max_heap 	= priority_queue<T>;
// template <class T> using min_heap	= priority_queue<T, vector<T>, greater<T>>;

// template <class T> bool ckmin(T &a, T &b) {
// 	return b < a ? a = b, 1 : 0;
// }
// template<class T> bool ckmax(T &a, T &b) {
// 	return b > a ? a = b, 1 : 0;
// }

// using LL 			        = long long;
// using LLL                               = __int128_t;
// using LD 			        = long double;

// const int mod 	                        = 1e9 + 7;
// const int MOD	                        = 998244353;
// const int N                             = 2e5 + 5;

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0); cout.tie(0);

//         auto solo_leveling = [&](int testcase_number) -> void {
//                 int x; cin >> x;

//                 auto a = V<int>(0, x);
//                 // FOR(i, x) cin >> a[i];
                
//         };

//         int testcases;
//         cin >> testcases;
//         FOR(testcase_number, testcases) solo_leveling(testcase_number);
//         return 0;
// }
