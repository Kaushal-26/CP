#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);

        auto solve = [&]() -> void {
                int N, K; std::cin >> N >> K;

                std::vector<int> A(N), C(N);
                for (auto &a : A) std::cin >> a, -- a, ++ C[a];

                if (N % K) {
                        std::cout << 0 << "\n";
                        return;
                }

                int window = N;
                for (int i = 0; i < N; ++i) if (C[i] % K) {
                        std::cout << 0 << "\n";
                        return;                    
                } else {
                        C[i] /= K;
                        window += C[i];
                }

                int64_t res = int64_t(N) * (N + 1) / 2;
                for (int i = window + 1; i <= N; ++ i) {
                        std::cout << "LOL: " << N - i + 1 << "\n";
                        res -= N - i + 1;
                }

                std::cout << res << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
