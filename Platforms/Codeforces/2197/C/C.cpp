#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int64_t P, Q; std::cin >> P >> Q;
                if (P >= Q) {
                        std::cout << "Alice\n";
                } else if (2 * (Q - P) > P || 3 * (Q - P) > Q) {
                        std::cout << "Alice\n";
                } else {
                        std::cout << "Bob\n";
                }
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
