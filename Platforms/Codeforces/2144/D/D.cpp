#include <bits/stdc++.h>

#ifdef Kaushal_26
        #include <debug.h>
#else    
        #define clog                            if (0) std::cerr
        #define dbg(...)                        42
        #define DB(...)                         42
#endif

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);

        auto solve = [&]() -> void {
                int N, Y; std::cin >> N >> Y;

                std::vector<int> C(N);
                for (auto &c : C) std::cin >> c;

                int max = std::ranges::max(C);
                if (max == 1) {
                        std::cout << N << "\n";
                        return;
                }

                std::vector<int> P(max + 1);
                for (auto &c : C) ++ P[c];
                for (int i = 1; i <= max; ++i) P[i] += P[i - 1];

                int64_t answer = LLONG_MIN;
                for (int x = 2; x <= max; ++x) {
                        int64_t result = -int64_t(Y) * N;
                        for (int i = 1, current_slider, extra_price_tags; (i - 1) * x <= max; ++i) {
                                current_slider = P[std::min(i * x, max)] - P[(i - 1) * x];
                                extra_price_tags = std::min(P[i] - P[i - 1], current_slider);

                                result += extra_price_tags * int64_t(Y) + current_slider * int64_t(i);
                        }
                        clog << dbg(x) << dbg(result) << "\n";
                        answer = std::max(answer, result);
                }

                std::cout << answer << "\n";
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}