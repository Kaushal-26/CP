#include <bits/stdc++.h>

int main() {
        #ifdef Kaushal_26
        auto start_time = std::chrono::high_resolution_clock::now();
        #endif

        auto solve = [&]() -> void {
                std::string S[5];
                for (int i = 0; i < 5; ++i) std::cin >> S[i];

                int res = 5;
                for (int i = 0, cnt = 0; i < 5; ++i) {
                        cnt = 0;
                        for (int j = 0; j < 5; ++j) cnt += S[i][j] == '.';
                        res = std::min(res, cnt);
                }

                for (int j = 0, cnt = 0; j < 5; ++j) {
                        cnt = 0;
                        for (int i = 0; i < 5; ++i) cnt += S[i][j] == '.';
                        res = std::min(res, cnt);
                }

                int cnt = 0;
                for (int i = 0; i < 5; ++i) {
                        cnt += S[i][i] == '.';
                }
                res = std::min(res, cnt);

                cnt = 0;
                for (int i = 0, j = 4; i < 5; ++i, --j) {
                        cnt += S[i][j] == '.';
                }
                res = std::min(res, cnt);

                std::cout << res << "\n";
        };

        int testcases = 1;// std::cin >> testcases;
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