#include <bits/stdc++.h>

int main() {
        #ifdef Kaushal_26
        auto start_time = std::chrono::high_resolution_clock::now();
        #endif

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                int L = 1, R = N, ans = R;
                while (L <= R) {
                        int mid = (L + R) / 2;

                        int64_t tk = 0;
                        for (int i = 1; i <= mid; ++i) {
                                tk += (mid / i) * int64_t(i);
                        }

                        if (tk >= N) {
                                ans = mid;
                                R = mid - 1;
                        } else {
                                L = mid + 1;
                        }
                }

                std::cout << ans << "\n";

                std::vector<int> a(N);
                int cur = ans, cnt = 0, x = 1, tk = 0;
                for (int i = 0; i < N; ++i) {
                        a[i] = x;
                        ++ cnt;
                        if (cnt == cur) {
                                ++ x;
                                cnt = 0;
                                tk ++;
                                if (tk == ans / cur) {
                                        cur--;
                                        tk = 0;
                                }
                        }
                }

                // for (auto &el : a) std::cout << el << " ";
                std::cout << "\n";
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