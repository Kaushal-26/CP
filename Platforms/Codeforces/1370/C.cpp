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

bool isPrime(int x) {
        for(int i = 2; i * i <= x; i++) if(x % i == 0) return 0;
        return 1;
}

void solve() {
        int n; cin >> n;

        if(n == 1) {
                cout << "FastestFinger\n";
                return;
        }
        
        if(n % 2 || n == 2) {
                cout << "Ashishgup\n";
                return;
        }

        int x = __builtin_ctz(n);

        if((1LL << x) == n) {
                cout << "FastestFinger\n";
                return;
        }

        if(isPrime(n / 2)) {
                cout << "FastestFinger\n";
                return;
        }

        cout << "Ashishgup\n";
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