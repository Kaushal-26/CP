#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);

        auto solve = [&]() -> void {
                int N, M; std::cin >> N >> M;

                std::vector<std::array<int, 2>> V(N + 1);
                for (int i = 1; i <= N; ++i) std::cin >> V[i][0] >> V[i][1];

                int points = 0;
                for (int i = 0; i <= N; ++i) {
                        if (i + 1 <= N) {
                                if (V[i + 1][1] != V[i][1]) {
                                        points += V[i + 1][0] - V[i][0];
                                        if ((V[i + 1][0] - V[i][0]) % 2 == 0) {
                                                points --;                                        
                                        }
                                } else {
                                        points += V[i + 1][0] - V[i][0];
                                        if ((V[i + 1][0] - V[i][0]) % 2) {
                                                points --;                                        
                                        }
                                }
                        } else {
                                points += M - V[i][0];
                        }
                }

                std::cout << points << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
