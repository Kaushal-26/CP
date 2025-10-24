#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N, K; std::cin >> N >> K;

                std::string S; std::cin >> S;

                int count = 0;
                for (int i = 0; i < N; ++i) if (S[i] == '1') {
                        bool found = false;
                        for (int j = 0; j < K - 1 && !found; ++j) if (i - j - 1 >= 0) {
                                found |= (S[i - j - 1] == '1');
                        } else {
                                break;
                        }
                        count += found == false;
                }

                std::cout << count << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
