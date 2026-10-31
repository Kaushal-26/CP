#include <bits/stdc++.h>

int main() {
        #ifdef Kaushal_26
        auto start_time = std::chrono::high_resolution_clock::now();
        #endif

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> A(N);
                for (auto &a : A) std::cin >> a;

                std::vector<int> L(N), R(N);
                for (int i = 0; i < N; ++i) {
                        L[i] = (A[i] - A[0]) / 2;
                        R[i] = (A[N - 1] - A[i]) / 2;
                }

                for (int i = 0; i < N; ++i) {
                        if (i == 0 || i == N - 1) {
                                std::cout << std::max(L[i], R[i]) << "\n";
                                continue;
                        }
                        int f1 = std::max(L[i], R[i + 1])  + (A[i + 1] - A[i]) / 2;
                        int f2 = std::max(R[i], L[i - 1]) + (A[i] - A[i - 1]) / 2;
                        std::cout << std::min(f1, f2) << "\n";
                }
                
        };

        int testcases = 1; // std::cin >> testcases;
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