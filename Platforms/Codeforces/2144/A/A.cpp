#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> A(N);
                for (auto &a : A) std::cin >> a;

                for (int l = 0; l < N; ++l) {
                        for (int r = l + 1; r + 1 < N; ++r) {
                                int S1 = 0, S2 = 0, S3 = 0;
                                for (int i = 0; i <= l; ++i) S1 += A[i], S1 %= 3;
                                for (int i = l + 1; i <= r; ++i) S2 += A[i], S2 %= 3;
                                for (int i = r + 1; i < N; ++i) S3 += A[i], S3 %= 3;
                                std::set<int> S = {S1, S2, S3};
                                if ((int) S.size() == 1 || (int) S.size() == 3) {
                                        std::cout << l + 1 << " " << r + 1 << "\n";
                                        return;
                                }
                        }
                }

                std::cout << "0 0\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
