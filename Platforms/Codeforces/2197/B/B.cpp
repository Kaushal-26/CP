#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> A(N), B(N);
                for (auto &a : A) std::cin >> a;
                for (auto &b : B) std::cin >> b;

                std::ranges::reverse(A);

                for (int i = 0, j = 0; i < N; ++i) {
                        j = i;
                        while (j < N && B[i] == B[j]) ++j;
                        while ((int) A.size() && A.back() != B[i]) {
                                A.pop_back();
                        }

                        if ((int) A.size() && A.back() == B[i]) {
                                A.pop_back();
                        } else {
                                std::cout << "NO\n";
                                return;
                        }

                        i = j - 1;
                }

                std::cout << "YES\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
