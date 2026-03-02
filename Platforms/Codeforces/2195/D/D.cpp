#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int64_t> F(N);
                for (auto &f : F) std::cin >> f;

                // f(1) = a2 + 2a3 + 3a4 + 4a5 + 5a6 + ...
                // f(2) = a1 + a3 + 2a4 + 3a5 + 4a6 + ...
                // f(3) = 2a1 + a2 + a4 + 2a5 + 3a6 + ...
                // f(4) = 3a1 + 2a2 + a3 + a5 + 2a6 + ...

                // f(1) - f(2) = a1 - a2 + a3 + a4 + a5 + a6 + ...
                // f(1) - f(3) = -2a1 + 2a3 + 2a4 + 2a5 + 2a6 + ...
                // f(1) - f(4) = -3a1 - a2 + a3 + 3a4 + 3a5 + 3a6 + ...


                // 2(f(1) - f(2)) = 2a1 - 2a2 + 2a3 + 2a4 + 2a5 + 2a6 + ...
                // f(1) - f(3) = -2a1 + 2a3 + 2a4 + 2a5 + 2a6 + ...
                // ------------------------------------------------
                // 4a1 - 2a2


                // 3(f(1) - f(2)) = 3a1 - 3a2 + 3a3 + 3a4 + 3a5 + 3a6 + ...
                // f(1) - f(4) = -3a1 - a2 + a3 + 3a4 + 3a5 + 3a6 + ...
                // ------------------------------------------------
                // 6a1 - 2a2 + 2a3

                // 2(f(1) - f(4)) = 6a1 - 2a2 + 2a3 + 6a4 + 6a5 + 6a6 + ...
                // 3(f(1) - f(3)) = -6a1 + 6a3 + 6a4 + 6a5 + 6a6 + ...
                // -------------------------------------------------
                // 12a1 - 2a2 - 4a3

                if (N == 2) {
                        std::cout << F[1] << " " << F[0] << "\n";
                        return;
                } else if (N == 3) {
                        int a0 = (F[1] + (F[2] - F[0]) / 2) / 2;
                        int a2 = F[1] - a0;
                        int a1 = F[2] - 2 * a0;
                        std::cout << a0 << " " << a1 << " " << a2 << "\n";
                        return; 
                }

                std::vector<int64_t> a(N, -1);
                for (int i = 0; i + 3 < N; i++) {
                        int64_t f1 = 2 * (F[i] - F[i + 1]) - (F[i] - F[i + 2]);
                        int64_t f2 = 3 * (F[i] - F[i + 1]) - (F[i] - F[i + 3]);
                        int64_t f3 = 2 * (F[i] - F[i + 3]) - 3 * (F[i] - F[i + 2]);

                        std::cout << f1 << " " << f2 << " " << f3 << std::endl;
                        std::cout << f2 - f3 << " " << 3 * (f2 - f1) << std::endl;

                        int64_t a1 = f3 - f1;
                        assert(a1 % 3 == 0);
                        a1 /= 3;

                        int64_t a3 = f1 - f2;
                        // assert((f2 - f1 + 2 * a3) % 2 == 0);
                        // int64_t a1 = (f2 - f1 + 2 * a3) / 2;
                        // assert((4 * a1 - f1) % 2 == 0);
                        int64_t a2 = (4 * a1 - f1) / 2;

                        std::cout << a1 << " " << a2 << " " << a3 << std::endl;
                }

                for (auto &el : a) std::cout << el << " ";
                std::cout << std::endl;

                // a[0] = F[N - 1];
                // for (int i = 1; i + 1 < N; ++i) {
                //         a[0] -= a[i] * std::abs(i - (N - 1));
                // }
                // assert(a[0] % (N - 1) == 0);
                // a[0] /= (N - 1);

                // a[N - 1] = F[0];
                // for (int i = 0; i + 1 < N; ++i) {
                //         a[N - 1] -= a[i] * std::abs(i);
                // }
                // assert(a[N - 1] % (N - 1) == 0);
                // a[N - 1] /= (N - 1);

                for (auto &el : a) std::cout << el << " ";
                std::cout << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
