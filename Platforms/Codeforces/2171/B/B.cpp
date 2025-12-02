#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> A(N);
                for (auto &a : A) std::cin >> a;

                if (A[0] == -1 || A[N - 1] == -1) {
                        std::cout << "0\n";
                } else {
                        std::cout << std::abs(A[N - 1] - A[0]) << "\n";
                }

                int i = 0;
                if (A[i] == -1) {
                        std::cout << (A[N - 1] == -1 ? 0 : A[N - 1]) << " ";
                        ++i;
                }

                for (; i + 1 < N; ++i) std::cout << (A[i] == -1 ? 0 : A[i]) << " ";

                if (A[i] == -1) {
                        std::cout << (A[0] == -1 ? 0 : A[0]) << "\n";
                } else {
                        std::cout << A[N - 1] << "\n";
                }
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
