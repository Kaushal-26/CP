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

mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int rn(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

void solve(int test_number) {
        int n = rn(5, 9), x = rn(1, 1000);
        cout << n << " " << x << "\n";
        for(int i = 0; i < n; i++) cout <<  rn(1, 1000) << " ";
        cout << "\n";
}

 
signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        cin.tie(0) -> sync_with_stdio(0);
        
        int T = 5;
        cout << T << endl;
        for(int i = 1; i <= T; i++) {
                clog << '\n' << "\033[36m" << string(100, '-') <<  "\033[39m" << '\n' << '\n';
                solve(i);
                if(i == T) clog << '\n' << "\033[36m" << string(100, '-') <<  "\033[39m";
        }

        #ifdef Kaushal_26
                auto end = std::chrono::high_resolution_clock::now();
                clog << fixed << setprecision(9);
                clog << "\n\n\033[35mExecution time: \033[31m" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-9 << "\033[34m seconds\033[39m." << endl;
        #endif
}
 
// 1.77245