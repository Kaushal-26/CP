#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N, M; std::cin >> N >> M;

                std::vector<int> A(M);
                for (auto &a : A) std::cin >> a;

                bool is_increasing = true;
                for (int i = 1; i < M; ++ i) is_increasing &= A[i - 1] < A[i];

                if (!is_increasing) {
                        std::cout << "1\n";
                        return;
                }

                std::cout << N - M - A[0] + 2 << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}