#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                int ct = 0;
                for (int i = 1; i <= 1000; ++i) {
                        int j = i + N, x = 0;
                        while (j) x += j % 10, j /= 10;
                        ct += i == x;
                }

                std::cout << ct << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}