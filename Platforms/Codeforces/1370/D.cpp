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

int n, k;
const int N = 2e5 + 5;
int a[N];

void brute() {
        int mn = 1e18;
        vector<int> store;
        for(int bt = 0; bt < 1LL << n; bt++) {
                if(__builtin_popcount(bt) != k) continue;
                vector<int> s;
                for(int i = 0; i < n; i++) if(bt >> i & 1) s.push_back(i);

                int o = 0, e = 0;
                for(int i = 0; i < (int)s.size(); i++) {
                        if(i % 2) e = max(e, a[s[i]]);
                        else o = max(o, a[s[i]]);
                }

                if(mn > min(o, e)) {
                        mn = min(o, e);
                        store = s;
                }
        }

        clog << db(mn) << '\n';
        clog << db(store) << endl;
}

void solve() {
        cin >> n >> k;

        map<int, int> sit;
        for(int i = 0; i < n; i++) {
                cin >> a[i];
                sit[a[i]]++;
        }

        // brute();

        auto exists = [&](int val) -> bool {
                return sit.find(val) != sit.end();
        };

        int l = 0, r = 1e9, ans = r;
        while(l <= r) {
                int mid = (l + r) / 2;

                int cntE = 0, cntO = 0;
                int f = 0;

                // Even
                for(int i = 0; i < n; i++) {
                        if(!f) {
                                if(a[i] <= mid) {
                                        f ^= 1;
                                        cntE++;
                                }
                        } else {
                                cntO++;
                                f ^= 1;
                        }
                }

                if(cntE >= (k + 1) / 2 && cntO >= k / 2) {
                        r = mid - 1;
                        if(exists(mid)) ans = mid;
                        continue;
                }
                
                cntE = cntO = f = 0;
                // Odd
                for(int i = 0; i < n; i++) {
                        if(!f) {
                                f ^= 1;
                                cntE++;
                        } else {
                                if(a[i] <= mid) {
                                        f ^= 1;
                                        cntO ++;
                                }
                        }
                }

                if(cntO >= k / 2 && cntE >= (k + 1) / 2) {
                        r = mid - 1;
                        if(exists(mid)) ans = mid;
                } else {
                        l = mid + 1;
                }
        }

        cout << ans << '\n';
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
                clog << "\n\n\033[35mExecution time: \033[31m" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-9 << "\033[34m seconds\033[39m." << endl;
        #endif
}
 
// 1.77245