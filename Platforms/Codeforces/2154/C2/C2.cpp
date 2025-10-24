#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> A(N);
                for (auto &a : A) std::cin >> a;

                std::vector<int64_t> B(N);
                for (auto &b : B) std::cin >> b;

                std::map<int, int> H;
                auto go = [&](int value, int add) -> bool {
                        if (value == 1) return false;

                        bool ret = false;
                        for (int d = 1; d * d <= value; ++ d) {
                                if (value % d == 0) {
                                        if (d > 1 && H[d] > 0) {
                                                ret |= true;
                                        }
                                        if (H[value / d] > 0) {
                                                ret |= true;
                                        }

                                        // std::cout << "Add: " << add << " " << H[d] << " " << H[value / d] << "\n";
                                        if (d > 1) H[d] += add;
                                        H[value / d] += add;
                                        // std::cout << "Add: " << add << " " << H[d] << " " << H[value / d] << "\n";
                                }
                        }
                        return ret;
                };

                int64_t res = INT_MAX;

                for (int i = 0; i < N; ++i) {
                        if (go(A[i], 1)) {
                                res = std::min(res, int64_t(0));
                        }
                }

                for (int i = 0; i < N; ++i) {
                        if (go(A[i] + 1, 0)) {
                                res = std::min(res, B[i]);
                        }
                }

                int max = *max_element(A.begin(), A.end());
                for (int i = 0; i < N; ++i) {
                        go(A[i], -1);
                        for (auto [x, y] : H) {
                                if (y) {
                                        for (int j = 1; j * x <= max; ++j) {
                                                std::cout << "lol: " << j << "  " << x << " " << j * x << "\n";
                                                if (j * x >= A[i]) {
                                                        res = std::min(res, (j * x - A[i]) * B[i]); 
                                                }
                                        }
                                }
                        }
                        go(A[i], 1);
                }

                int64_t o1 = INT_MAX, o2 = INT_MAX;
                for (int i = 0; i < N; ++i) {
                        if (A[i] % 2) {
                                if (o1 == INT_MAX) o1 = B[i];
                                else if (o2 == INT_MAX) {
                                        o2 = B[i];
                                        if (o1 > o2) std::swap(o1, o2);
                                }
                                else {
                                        if (B[i] < o1) {
                                                o2 = o1;
                                                o1 = B[i];
                                        } else if (B[i] < o2) {
                                                o2 = B[i];
                                        }
                                }
                        }
                }

                if (o1 != INT_MAX && o2 != INT_MAX) {
                        res = std::min(res, o1 + o2);
                }

                std::cout << res << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
