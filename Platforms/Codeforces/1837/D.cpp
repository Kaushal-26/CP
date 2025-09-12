#ifdef Kaushal_26
        #include <debug.h>
#else
        #include <bits/stdc++.h>

        using namespace std;

        #define clog            if (0) cerr
        #define lvl(...)        if (0) cerr
        #define dbg(...)        42
#endif

#define int long long

void solve() {
        int n; cin >> n;

        string s; cin >> s;

        int cnt = 0, pos = 1;
        for(auto &el : s) {
                if(el == '(') cnt++;
                else cnt--;
                if(cnt < 0) pos = 0;
        }

        if(cnt != 0) {
                cout << "-1\n";
                return;
        }

        if(pos) {
                cout << "1\n";
                for(int i = 0; i < n; i++) cout << 1 << " \n"[i == n - 1];
                return; 
        }

        {
                ranges::reverse(s);

                cnt = 0, pos = 1;
                for(auto &el : s) {
                        if(el == '(') cnt++;
                        else cnt--;
                        if(cnt < 0) pos = 0;
                }

                if(pos) {
                        cout << "1\n";
                        for(int i = 0; i < n; i++) cout << 1 << " \n"[i == n - 1];
                        return; 
                }

                ranges::reverse(s);
        }

        vector<int> tk(n, 2);
        pos = cnt = 0;
        for(int i = 0; i < n; i++) {
                if(s[i] == ')') {
                        cnt--;
                        if(cnt < 0) {
                                pos ++;
                                tk[i] = 1;
                        }
                } else {
                        if(pos) {
                                tk[i] = 1;
                                pos --;
                        }
                        cnt++;
                }
        }

        cout << 2 << "\n";
        for(auto &el : tk) cout << el << " ";
        cout << "\n";
}
 
signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        cin.tie(0)->sync_with_stdio(0);
        
        int T = 1; cin >> T;
        for(int i = 1; i <= T; i++) {
                clog << '\n' << "\033[36m" << string(100, '-') <<  "\033[39m" << '\n' << '\n';
                solve();
                if(i == T) clog << '\n' << "\033[36m" << string(100, '-') << "\033[39m";
        }

        #ifdef Kaushal_26
                auto end = std::chrono::high_resolution_clock::now();
                clog << fixed << setprecision(15);
                clog << "\n\n\033[35mExecution time: \033[31m" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-15 << "\033[34m seconds\033[39m." << '\n' << '\n';
        #endif
        return 0;
}
 
// 1.77245