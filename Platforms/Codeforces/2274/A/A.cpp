#include <bits/stdc++.h>
#include <cassert>

int main() {
        #ifdef Kaushal_26
        auto start_time = std::chrono::high_resolution_clock::now();
        #endif

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                int token = 0;
                int a[N];
                for (int i = 0; i < N; ++i) {
                        std::cin >> a[i];

                        if (token <= a[i]) {
                                token = a[i] + (a[i] - token);
                        } else {
                                token = a[i] - (token - a[i]);
                        }
                }

                assert(token % 2 == 0);

                token /= 2;
                {
                        int new_token = 2 * token;
                        for (int i = 0; i < N; ++i) {
                                if (a[i] <= new_token) {
                                        new_token = a[i] + (a[i] - new_token);
                                } else {
                                        new_token = a[i] - (new_token - a[i]);
                                }
                        }
                        if (new_token == 0) {
                                std::cout << token << "\n";
                                return;
                        }
                }

                token = -token;
                int new_token = 2 * token;
                for (int i = 0; i < N; ++i) {
                        if (a[i] <= new_token) {
                                new_token = a[i] + (a[i] - new_token);
                        } else {
                                new_token = a[i] - (new_token - a[i]);
                        }
                }
                if (new_token == 0) {
                        std::cout << token << "\n";
                        return;
                }

                assert(false);
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