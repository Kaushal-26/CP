#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N, Q; std::cin >> N >> Q;

                std::string S; std::cin >> S;

                std::vector<int> queries(Q);
                for (auto &q : queries) std::cin >> q;

                std::vector<int> next(N), dis(N);
                for (int i = 0, j, ct; i < N; ++i) {
                        j = (i + 1) % N, ct = 0;
                        while (j != i && S[j] == 'A') {
                                ++j, j %= N;
                                ++ct;
                        }
                        next[i] = j;
                        dis[i] = ct;
                }

                for (auto &q : queries) {
                        int i = 0, time = 0;
                        if (next[0] == 0 && S[0] == 'A') {
                                std::cout << q << "\n";
                        } else {
                                time ++;
                                if (S[0] == 'A') {
                                        q --;
                                } else {
                                        q /= 2;
                                }

                                time += std::min(q, dis[i]);
                                q -= std::min(q, dis[i]);
                                i = next[i];

                                while (q > 0) {
                                        q /= 2;
                                        time ++;

                                        time += std::min(q, dis[i]);
                                        q -= std::min(q, dis[i]);
                                        i = next[i];
                                }

                                std::cout << time << "\n";
                        }
                }
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
