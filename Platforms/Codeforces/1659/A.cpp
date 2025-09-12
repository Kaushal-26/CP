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
        int n, a, b; cin >> n >> a >> b;

        for(int i = 1; i <= n; i++) {
                string S;
                int f = 0;
                int A = a, B = b;
                while(A + B > 0) {
                        if(!f) {
                                if(A > B) {
                                        int cnt = 0;
                                        while(cnt < i && A > 0) {
                                                A--;
                                                cnt++;
                                                S += 'R';
                                        }
                                } else {
                                        A--;
                                        S += "R";
                                }
                                if(A > 0 && B == 0) break;
                        } else {
                                if(B > A) {
                                        int cnt = 0;
                                        while(cnt < i && B > 0) {
                                                B--;
                                                cnt++;
                                                S += 'B';
                                        }
                                } else {
                                        B--;
                                        S += "B";
                                }
                                if(B > 0 && A == 0) break;
                        }
                        f ^= 1;
                }
                
                clog << db(i) << db(S) << endl;
                if(A + B == 0) {
                        cout << S << '\n';
                        return;
                }
        }
        assert(0);
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