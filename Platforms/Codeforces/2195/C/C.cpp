#include <bits/stdc++.h>

int N;
const int _N = 3e5 + 5, D = 8;
int dp[_N][D];
int A[_N];

int rec(int idx, int lastD) {
        if (idx == N) return 0;

        if (dp[idx][lastD] != -1) return dp[idx][lastD];

        if (lastD == A[idx] || 7 - lastD == A[idx]) {
                int ret = N + 1;
                for (int i = 1; i <= 6; ++i) if (lastD != i && 7 - lastD != i) 
                        ret = std::min(ret, rec(idx + 1, i) + 1);
                return dp[idx][lastD] = ret;
        }

        return dp[idx][lastD] = rec(idx + 1, A[idx]);
}

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                std::cin >> N;

                for (int i = 0; i < N; ++i) std::cin >> A[i];

                for (int i = 0; i <= N; ++i)
                        for (int j = 0; j < D; ++j) dp[i][j] = -1;

                std::cout << rec(0, 7) << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
