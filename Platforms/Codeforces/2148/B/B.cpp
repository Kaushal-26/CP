#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);

        auto solve = [&]() -> void {
                int N, M, X, Y; std::cin >> N >> M >> X >> Y;
                std::vector<int> A(N);
                for (auto &a : A) std::cin >> a;
                std::vector<int> B(M);
                for (auto &b : B) std::cin >> b;
                std::cout << N + M << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}