#include <bits/stdc++.h>

int main() {
        #ifdef Kaushal_26
        auto start_time = std::chrono::high_resolution_clock::now();
        #endif

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                int64_t a[N];
                for (int i = 0; i < N; ++i) std::cin >> a[i];

                int64_t ans = a[0];
                int64_t min = a[0], max = a[0];
                for (int i = 1; i < N; ++i) {
                        int64_t pos[3] = {a[i] - min, a[i], a[i] + max};
                        for (int j = 0; j < 3; ++j) {
                                ans = std::max(ans, pos[j]);
                        }

                        if (min < 0) {
                                min = a[i] + 2 * min;
                        } else {
                                min = a[i];
                        }
                        if (max > 0) {
                                max = a[i] + 2 * max;
                        } else {
                                max = a[i];
                        }
                }

                std::cout << ans << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                #ifdef Kaushal_26
                std::cout << "\n\n" << std::string(50, '=');
                std::cout << "\n\n" << "Testcase #" << i << ": ";
                #endif

                solve();
        }

        #ifdef Kaushal_26
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        std::cout << "\n\n" << std::string(50, '=');
        std::cout << "\n\n" << "Time taken: " << duration.count() << " milliseconds";
        std::cout << "\n\n" << std::string(50, '=') << "\n\n";
        #endif

        return 0;
}