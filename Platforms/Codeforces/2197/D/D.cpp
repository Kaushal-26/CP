#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> A(N);
                for (auto &a : A) std::cin >> a;

                std::map<int, std::set<int>> M;
                for (int i = 0; i < N; ++i) M[A[i]].insert(i);

                int res = 0;
                for (int dis = 1; dis < N; ++dis) {
                        for (int i = 1; i * i <= dis; i++) if (dis % i == 0) {
                                int j = dis / i;
                                int ct = 0;
                                if ((int) M[i].size() > (int) M[j].size()) {
                                        for (auto &m : M[j]) {
                                                if (M[i].find(m - dis) != M[i].end() || M[i].find(m + dis) != M[i].end()) {
                                                        ct ++;
                                                }
                                        }
                                } else {
                                        for (auto &m : M[i]) {
                                                if (M[j].find(m - dis) != M[j].end() || M[j].find(m + dis) != M[j].end()) {
                                                        ct ++;
                                                }
                                        }
                                }
                                if (i * i == dis) ct /= 2;

                                std::cout << dis << " " << i << " " << ct << "\n";
                                res += ct;
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
