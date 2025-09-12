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


void spiralOrder(vector<vector<int>>& g) {
int n = g.size(), m = g[0].size();

int cur = 1;
vector<int> ans;
int si = 0, sj = 0, ei = n - 1, ej = m - 1;
while(si <= ei && sj <= ej) {
        for(int i = sj; i <= ej; i++) {
                g[si][i] = cur++;
        }
        for(int i = si + 1; i <= ei; i++) {
                g[i][ej] = cur++;
        }
        if(si != ei)
        for(int i = ej - 1; i >= sj; i--) {
                g[ei][i] = cur++;
        }
        if(sj != ej)
        for(int i = ei - 1; i > si; i--) {
                g[i][sj] = cur++;
        }
        si++, ei--;
        sj++, ej--;
}
}


void solve() {
        int N; cin >> N;

        vector<vector<int>> a(N, vector<int>(N));

        spiralOrder(a);

        for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                        if(i == N / 2 && j == N / 2) {
                                cout << "T ";
                        } else {
                                 cout << a[i][j] << ' ';
                        }
                }
                cout << "\n";
        }
}
 
signed main() {
        #ifdef Kaushal_26
                auto begin = std::chrono::high_resolution_clock::now();
        #endif

        cin.tie(0) -> sync_with_stdio(0);
        
        int T = 1; // cin >> T;
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