#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> P(N);
                for (auto &p : P) std::cin >> p;

                int count_zeroes = std::ranges::count(P, 0);
                if (count_zeroes == 1) {
                        std::vector<int> H(N);
                        for (int i = 0; i < N; ++i) if (P[i]) H[P[i] - 1] = 1;
                        int missing = -1;
                        for (int i = 0; i < N; ++i) if (!H[i]) missing = i + 1;
                        for (int i = 0; i < N; ++i) if (!P[i]) P[i] = missing;
                }

                int start = 0, end = N - 1;
                while (start < N && P[start] - 1 == start) ++ start;
                while (end >= 0 && P[end] - 1 == end) -- end;

                std::cout << (start >= end ? 0 : end -  start + 1) << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
