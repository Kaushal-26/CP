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

int my_x;
int interactor(int x, int y) {
        return gcd(x + my_x, y + my_x);
}

int ask(int x, int y) {
        cout << "? " << x << " " << y << endl;
        int gcd;

        #ifdef Kaushal_26
                gcd = interactor(x, y);
        #else
                cin >> gcd;
        #endif
        return gcd;
}

void solve() {
        #ifdef Kaushal_26
                my_x = 4;
                clog << db(my_x) << endl;
        #endif

        int x = 0;
        for(int i = 0; i < 30; i++) {
                int g = ask((1LL << i) - x, (1LL << i) - x + (1LL << (i + 1)));
                clog << db((1LL << i) - x) << db((1LL << i) - x + (1LL << (i + 1))) << db(g) << endl;
                if(g == (1LL << (i + 1))) {
                        x |= 1LL << i;
                }
        }
        cout << "! " << x << endl;
}
 
signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        // cin.tie(0) -> sync_with_stdio(0);
        
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