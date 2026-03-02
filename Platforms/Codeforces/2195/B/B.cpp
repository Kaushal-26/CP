#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> a(N + 1), v(N + 1);
                for (int i = 1; i <= N; ++i) std::cin >> a[i];

                for (int i = 1; i <= N; ++i) {
                        if (v[i]) continue;

                        std::vector<int> t;
                        for (int j = i; j <= N; j *= 2) t.push_back(a[j]);

                        std::ranges::sort(t);
                        std::ranges::reverse(t);

                        for (int j = i; j <= N; j *= 2) {
                                v[j] = 1;
                                a[j] = t.back();
                                t.pop_back();
                        }
                }

                // for (int i = 1; i <= N; ++i) std::cout << a[i] << " \n"[i == N];

                bool inc = true;
                for (int i = 2; i <= N; ++i) inc &= a[i] >= a[i - 1];

                std::cout << (inc ? "YES\n" : "NO\n");
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
