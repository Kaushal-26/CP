#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> A(N);
                for (auto &a : A) std::cin >> a;

                int res = 0;
                for (int dis = 1; dis < N; ++dis) {
                        for (int i = 0; i + dis < N; i++) {
                                if ((int64_t(A[i]) * A[i + dis]) == dis) {
                                        ++ res;
                                }
                        }
                }

                std::cout << res << '\n';
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
