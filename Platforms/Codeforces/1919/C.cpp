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

void brute(vector<int> &a) {
        int N = a.size();
        
        int ans = 1e18;
        vector<int> X, Y;
        for(int i = 0; i < 1LL << N; i++) {
                vector<int> x, y;
                for(int j = 0; j < N; j++) {
                        if(i >> j & 1) x.push_back(a[j]);
                        else y.push_back(a[j]);
                }
                int cnt = 0;
                for(int j = 1; j < (int)x.size(); j++) cnt += x[j] > x[j - 1];
                for(int j = 1; j < (int)y.size(); j++) cnt += y[j] > y[j - 1];
                if(ans > cnt) {
                        ans = cnt;
                        X = x;
                        Y = y;
                }
        }

        clog << db(ans) << endl;
         for(int i = 0; i < 1LL << N; i++) {
                vector<int> x, y;
                for(int j = 0; j < N; j++) {
                        if(i >> j & 1) x.push_back(a[j]);
                        else y.push_back(a[j]);
                }
                int cnt = 0;
                for(int j = 1; j < (int)x.size(); j++) cnt += x[j] > x[j - 1];
                for(int j = 1; j < (int)y.size(); j++) cnt += y[j] > y[j - 1];
                if(ans == cnt) {
                        clog << db(x) << db(y) << endl;
                }
        }
}

void solve() {
        int N; cin >> N;

        vector<int> a(N);
        for(auto &el : a) cin >> el;

        clog << db(a) << endl;

        // brute(a);

        int cnt = 0;
        int F = 1e18, G = 1e18;
        for(int i = 0; i < N; i++) {
                if(F == a[i]) {
                        F = a[i];
                } else if(G == a[i]) {
                        G = a[i];
                } else if(F > a[i] && G > a[i]) {
                        if(F < G) {
                                F = a[i];
                        } else {
                                G = a[i];
                        }
                } else if(F > a[i]) {
                        F = a[i];
                } else if(G > a[i]) {
                        G = a[i];
                } else {
                        if(F < G) {
                                F = a[i];
                        } else {
                                G = a[i];
                        }
                        cnt++;
                }
        }

        cout << cnt << '\n';
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
                clog << "\n\n\033[35mExecution time: \033[31m" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-9 << "\033[34m seconds\033[39m." << '\n' << '\n';
        #endif
}
 
// 1.77245