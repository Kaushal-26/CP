#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                int a[N];
                for (int i = 0; i < N; ++i) std::cin >> a[i];

                for (int i = 0; i < N; ++i) if (a[i] == 67) {
                        std::cout << "YES\n";
                        return;
                }

                std::cout << "NO\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}