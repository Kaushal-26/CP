#ifdef Kaushal_26
        #include <debug.h>
#else
        #include <bits/stdc++.h>

        using namespace std;

        #define clog if (0) cerr
        #define lvl() if(0) cerr
        #define dbg(...) 42
#endif

#define int long long

void solve() {
        int n; cin >> n;


        vector<int> a(n);

        int a[n];
        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i <= n; i++) {
                int cnt = 0;
                for(int j = 0; j < n; j++) cnt += a[j] > i;
                if(cnt == i) {
                        cout << i << '\n';
                        return;
                }
        }

        lvl();
        clog << dbg(2) << endl;

        cout << "-1\n";
}
 
signed main() {
        cin.tie(0) -> sync_with_stdio(0);

        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();

                for(int testcase_number = 1; ; testcase_number++) {
                        clog << dbg(testcase_number) << endl;
                        clog << "\033[36m" << string(100, '-') <<  "\033[39m" << endl << endl;
                        solve();
                        clog << endl << "\033[36m" << string(100, '-') <<  "\033[39m" << endl;
                }

                auto end = std::chrono::high_resolution_clock::now();
                clog << fixed << setprecision(9);
                clog << "\n\n\033[35mExecution time: \033[31m" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-9 << "\033[34m seconds\033[39m." << endl;
        #else
                int T = 1; cin >> T;
                for(int i = 1; i <= T; i++) {
                        solve();
                }
        #endif        
}
 
// 1.77245