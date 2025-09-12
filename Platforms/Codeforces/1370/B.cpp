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

        vector<int> a[2];
        for(int i = 0, x; i < 2 * N; i++) {
                cin >> x;
                a[x % 2].push_back(i);
        }

        int tot = N - 1;
        for(int i = 0; i < 2; i++) {
                clog << db(a[i]) << endl;
                while((int)a[i].size() > 1 && tot > 0) {
                        --tot;
                        cout << a[i].back() + 1 << ' '; a[i].pop_back();
                        cout << a[i].back() + 1 << '\n'; a[i].pop_back();
                }
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
                clog << "\n\n\033[35mExecution time: \033[31m" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-9 << "\033[34m seconds\033[39m." << endl;
        #endif
}
 
// 1.77245