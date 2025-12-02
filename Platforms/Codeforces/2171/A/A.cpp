#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                int count = 0;
                for (int chickens = 0; chickens * 2 <= N; ++chickens)
                        if ((N - 2 * chickens) % 4 == 0)                                        
                                ++ count;

                std::cout << count << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
