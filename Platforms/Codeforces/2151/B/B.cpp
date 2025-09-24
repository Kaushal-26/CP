#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N, M; std::cin >> N >> M;

                std::string S; std::cin >> S;

                std::vector<int> A(M);
                for (auto &a : A) std::cin >> a;

                std::set<int> ret(A.begin(), A.end());

                int pit = 1;
                for (int turns = 0; turns < N; ++ turns) {
                        ++ pit;
                        if (S[turns] == 'B') {
                                while (ret.find(pit) != ret.end()) {
                                        ++ pit;
                                }
                        }
                        if (ret.find(pit) == ret.end()) {
                                ret.insert(pit);
                        }
                        if (S[turns] == 'B') {
                                ++ pit;
                                while (ret.find(pit) != ret.end()) {
                                        ++ pit;
                                }
                        }
                }

                std::cout << (int) ret.size() << "\n";
                for (auto &el : ret) std::cout << el << " ";
                std::cout << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
