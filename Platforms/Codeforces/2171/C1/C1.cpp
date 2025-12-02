#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> A(N);
                for (auto &a : A) std::cin >> a;

                std::vector<int> B(N);
                for (auto &b : B) std::cin >> b;

                int ct = 0;
                for (int i = 0; i < N; ++i) if (A[i] != B[i]) {
                        if (i % 2 == 0) {
                                if (ct == 2) {
                                        ct = 0;
                                } else {
                                        ct = 1;
                                }
                        }
                        else {
                                if (ct == 1) {
                                        ct = 0;
                                } else {
                                        ct = 2;
                                }
                        }
                }

                std::cout << (ct == 0 ? "Tie" : (ct == 1 ? "Ajisai" : "Mai")) << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
