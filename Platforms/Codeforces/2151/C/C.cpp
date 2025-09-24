#include <bits/stdc++.h>


#ifdef Kaushal_26
        #include <debug.h>
#else    
        #define clog                            if (0) std::cerr
        #define dbg(...)                        42
        #define DB(...)                         42
#endif

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> A(2 * N);
                for (auto &a : A) std::cin >> a;

                std::vector prefix_sum(2 * N + 1, std::vector<int64_t>(2, 0));
                for (int i = 0; i < 2 * N; ++i) {
                        prefix_sum[i + 1][0] = prefix_sum[i][0];
                        prefix_sum[i + 1][1] = prefix_sum[i][1];
                        prefix_sum[i + 1][i % 2] += A[i];
                }

                int64_t extra = 0;
                std::vector<int64_t> res(N);
                for (int i = 0, j = 0; i < N; ++i) {
                        j = 2 * N - 1 - i;
                        if (i >= j) break;

                        clog << dbg(i) << dbg(j) << dbg(extra) << dbg(prefix_sum[j + 1][j % 2]) << dbg(prefix_sum[i][j % 2]) << dbg(prefix_sum[j + 1][!(j % 2)]) << dbg(prefix_sum[i][!(j % 2)]) << std::endl;

                        res[i] = (prefix_sum[j + 1][j % 2] - prefix_sum[i][j % 2]) - (prefix_sum[j + 1][!(j % 2)] - prefix_sum[i][!(j % 2)]) + extra;
                        extra += A[j];
                        extra -= A[i];
                }

                for (auto &el : res) std::cout << el << " ";
                std::cout << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
