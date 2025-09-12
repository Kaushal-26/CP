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

template <class T> using max_heap 	= priority_queue<T>;
template <class T> using min_heap	= priority_queue<T, vector<T>, greater<T>>;

void solve() {
        int n, k; cin >> n >> k;

        vector<int> a(n);
        for(auto &el : a) cin >> el;

        vector<int> pf(n + 1), sf(n + 1);

        int L = 1, R = 1e15, ans = R;
        while(L <= R) {
                int M = (L + R) / 2;

                for(int i = 0; i <= n; i++) pf[i] = sf[i] = 0;

                int f = 0;
                max_heap<int> PQ;
                int sum = 0;
                for(int i = 0; i < n; i++) {
                        PQ.push(a[i]);
                        sum += a[i];
                        while(sum > M) {
                                sum -= PQ.top();
                                PQ.pop();
                        }
                        pf[i + 1] = PQ.size();
                }

                sum = 0;
                while(!PQ.empty()) PQ.pop();
                for(int i = n - 1; i >= 0; i--) {
                        PQ.push(a[i]);
                        sum += a[i];
                        while(sum > M) {
                                sum -= PQ.top();
                                PQ.pop();
                        }
                        sf[i] = PQ.size();
                }

                for(int i = 0; i <= n; i++) if(pf[i] + sf[i] >= k) f = 1;

                if(f) {
                        ans = M;
                        R = M - 1;
                } else {
                        L = M + 1;
                }
        }

        cout << ans << "\n";
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