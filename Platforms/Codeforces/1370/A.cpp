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

void solve() {
        int N; cin >> N;

        cout << N / 2 << '\n';
}
 
signed main() {
        cin.tie(0) -> sync_with_stdio(0);

        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();

                for(int testcase_number = 1; ; testcase_number++) {
                        clog << db(testcase_number) << endl;
                        clog << "\033[36m" << string(100, '-') <<  "\033[39m" << '\n' << '\n';
                        solve();
                        clog << '\n' << "\033[36m" << string(100, '-') <<  "\033[39m" << '\n';
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