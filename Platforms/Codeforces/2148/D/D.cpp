#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::deque<int> A[2];
                for (int i = 0, x; i < N; ++ i) std::cin >> x, A[x & 1].push_back(x);

                int64_t sum = 0;
                if ((int) A[1].size() == 0) {
                        std::cout << sum << "\n";
                } else {
                        std::ranges::sort(A[1]);

                        sum += A[1].back(); A[1].pop_back();
                        sum += std::accumulate(A[0].begin(), A[0].end(), 0LL);

                        bool flag = true;
                        while (A[1].size()) {
                                if (flag) {
                                        A[1].pop_front();
                                } else {
                                        sum += A[1].back();
                                        A[1].pop_back();
                                }
                                flag ^= 1;
                        }
                        std::cout << sum << "\n";
                }
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
