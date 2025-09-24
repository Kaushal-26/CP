#include <bits/stdc++.h>
#include <atcoder/modint.hpp>

using mint = atcoder::modint998244353;

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> A(N);
                for (auto &a : A) std::cin >> a;

                int64_t sum = std::accumulate(A.begin(), A.end(), 0LL); 

                if (sum != N) {
                        std::cout << "0\n";
                        return;
                }

                for (int i = (N + 1) / 2; i < N; ++i) if (A[i] > 0) {
                        std::cout << "0\n";
                        return;
                }

                mint res = 1;
                int cnt = 0;
                for (int i = 0; i < (N + 1) / 2; ++i) {
                        cnt += A[i] > 0;
                }

                std::cout << res.val() << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
