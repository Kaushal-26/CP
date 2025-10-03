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
                int N, Q; std::cin >> N >> Q;

                std::vector<int> B(N); 
                for (auto &b : B) std::cin >> b;

                std::vector<std::array<int, 2>> queries;
                for (int i = 0, a, b; i < Q; ++i) {
                        std::cin >> a >> b; -- a, -- b;
                        queries.push_back({a, b});
                }

                std::vector<int> next_good_r(N, N);
                for (int i = N - 2, cur = N; i >= 0; --i) {
                        if (B[i] == B[i + 1]) {
                                cur = i + 1;
                        }
                        next_good_r[i] = cur;
                }

                std::vector<std::vector<int>> prefix_sum(2, std::vector<int>(N + 1));
                for (int i = 0; i < N; ++i) {
                        prefix_sum[0][i + 1] = prefix_sum[0][i];
                        prefix_sum[1][i + 1] = prefix_sum[1][i];

                        if (B[i] == 0) prefix_sum[0][i + 1] ++;
                        else prefix_sum[1][i + 1] ++;
                }

                clog << dbg(next_good_r) << std::endl;

                for (auto &[l, r]: queries) {
                        auto zeroes = prefix_sum[0][r + 1] - prefix_sum[0][l];
                        auto ones = prefix_sum[1][r + 1] - prefix_sum[1][l];
                        if (zeroes % 3 != 0 || ones % 3 != 0) {
                                std::cout << "-1\n";
                        } else {
                                if (next_good_r[l] >= r) {
                                        std::cout << zeroes / 3 + ones / 3 + 1 << "\n";
                                } else {
                                        std::cout << zeroes / 3 + ones / 3 << "\n";
                                }
                        }
                }
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
