#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> A(N);
                for (auto &a : A) std::cin >> a;

                int max = 0;
                for (int i = 0; i < N; ++i) {
                        max = std::max(max, A[i]);
                        if (i & 1) {
                                A[i] = max;
                        }
                }

                int64_t res = 0;
                for (int i = 0; i + 1 < N; ++i) {
                        if (~i & 1) {
                                if (A[i] >= A[i + 1]) {
                                        res += A[i] - A[i + 1] + 1;
                                        A[i] = A[i + 1] - 1;
                                }
                        } else {
                                if (A[i] <= A[i + 1]) {
                                        res += A[i + 1] - A[i] + 1;
                                        A[i + 1] = A[i] - 1;
                                }
                        }
                }

                std::cout << res << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
