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
        string s; cin >> s;

        s = "0" + s + "1";
        int n = s.size();

        for(int i = 0; i + 1 < n; i++) {
                if(s[i + 1] != '?') continue;
                int j = i + 1;
                while(j + 1 < n && s[j] == '?') ++j;
                if(s[i] == s[j]) {
                        for(int k = i; k < j; k++) {
                                s[k] = s[i];
                        }
                } else {
                        for(int k = i + 1; k < j; k++) {
                                s[k] = '0';
                        }
                }
                i = j - 1;
        }

        for(int i = 1; i + 1 < n; i++) cout << s[i];
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