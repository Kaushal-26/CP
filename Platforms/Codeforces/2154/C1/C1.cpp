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

                std::map<int, int> H;
                auto go = [&](int value, bool add) -> bool {
                        if (value == 1) return false;

                        for (int d = 1; d * d <= value; ++ d) {
                                if (value % d == 0) {
                                        if (d > 1 && H[d] > 0) {
                                                return true;
                                        }
                                        if (H[value / d] > 0) {
                                                return true;
                                        }
                                        if (add) {
                                                if (d > 1) H[d] ++;
                                                H[value / d] ++;
                                        }
                                }
                        }
                        return false;
                };

                for (int i = 0; i < N; ++i) {
                        if (go(A[i], true)) {
                                std::cout << "0\n";
                                return;
                        }
                }

                for (int i = 0; i < N; ++i) {
                        if (go(A[i] + 1, false)) {
                                std::cout << "1\n";
                                return;
                        }
                }

                std::cout << "2\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
