#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N, K; std::cin >> N >> K;

                std::vector<int> A(N);
                for (auto &a : A) std::cin >> a;

                std::vector<int> C(N + 1), P(N + 1);
                for (auto &a : A) ++ C[a];

                for (int i = 1; i <= N; ++i) P[i] = P[i - 1] + C[i];

                for (int i = N; i >= 1; --i) {
                        int done = P[i - 1] + P[std::min(N, 4 * i - 1)] - P[i] - (2 * i <= N ? C[2 * i] : 0) - (3 * i <= N ? C[3 * i] : 0);

                        if (done <= K) {
                                std::cout << i << "\n";
                                return;
                        }
                }
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
