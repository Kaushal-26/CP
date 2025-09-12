#ifdef Kaushal_26
        #include <debug.h>
#else
        #include <bits/stdc++.h>

        using namespace std;

        #define clog            if (0) cerr
        #define lvl(...)        42
        #define dbg(...)        42
#endif

#define int long long

void solve() {
        int n, m; cin >> n >> m;

        vector<int> a(n), b(m);
        for(auto &el : a) cin >> el;
        for(auto &el : b) cin >> el;

        int A = accumulate(a.begin(), a.end(), 0LL);
        int B = accumulate(b.begin(), b.end(), 0LL);

        if(A == B) {
                cout << "Draw\n";
        } else if(A > B) {
                cout << "Tsondu\n";
        } else {
                cout << "Tenzing\n";
        }
}

signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        cin.tie(0)->sync_with_stdio(0);

        int TestCases = 1; cin >> TestCases;
        for(int TestCase = 1; TestCase <= TestCases; TestCase++) {
                clog << "\n"; dbg(TestCase);
                solve();
        }

        #ifdef Kaushal_26
                auto end = std::chrono::high_resolution_clock::now();
                clog << fixed << setprecision(15) << "\n";
                auto Execution_Time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-9;
                dbg(Execution_Time);
        #endif
        return 0;
}

// 1.77245