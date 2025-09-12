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
        int n; cin >> n;

        vector<int> a(n);
        for(int i = 1, x; i < n; i++) {
                cin >> x; --x;
                a[x]++;
        }       

        a.push_back(1);

        ranges::sort(a, greater<int>());
        while(a.size() > 0 && a.back() <= 0) a.pop_back();

        int ans = 0;
        n = a.size();
        for(int i = 0; i < n; i++) {
                a[i] -= n - i;
                ans++;
        }

        while(true) {
                ranges::sort(a, greater<int>());
                while(a.size() > 0 && a.back() <= 0) a.pop_back();

                if((int)a.size() == 0) break;

                a[0]--;

                ans++;
                n = a.size();
                for(int i = 0; i < n; i++) a[i]--;
        }

        cout << ans << '\n';
}
 
signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        cin.tie(0) -> sync_with_stdio(0);
        
        int T = 1; cin >> T;
        for(int i = 1; i <= T; i++) {
                clog << endl << "\033[36m" << string(100, '-') <<  "\033[39m" << endl << endl;
                solve();
                if(i == T) clog << endl << "\033[36m" << string(100, '-') <<  "\033[39m";
        }

        #ifdef Kaushal_26
                auto end = std::chrono::high_resolution_clock::now();
                clog << fixed << setprecision(9);
                clog << "\n\n\033[35mExecution time: \033[31m" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() * 1e-9 << "\033[34m seconds\033[39m." << '\n' << '\n';
        #endif
}
 
// 1.77245