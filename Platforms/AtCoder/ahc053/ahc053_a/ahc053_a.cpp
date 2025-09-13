#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);

        const int64_t MAX = 1'000'000'000'000'000;

        int N = 500, M = 50;
        int64_t L = MAX - 2 * (MAX / 1000), U = MAX + 2 * (MAX / 1000);

        const int MAX_BITS = 42;

        // const int64_t vU = (1LL << MAX_BITS) - 1;
        // std::cout << vU << " " << (vU > (U - L)) << std::endl;

        // auto required_digits = [&](int64_t value) -> void {
        //         int64_t sum = 0, digits = 1;
        //         for (digits = 1; sum < value; ++ digits) sum += digits;
        //         std::cout << digits << " " << sum << " " << value << "\n";
        // };

        // required_digits(U - L);

        std::cin >> N >> M >> L >> U;

        std::vector<int> give(MAX_BITS);
        int can_give = (N - M) / MAX_BITS, extra = (N - M) % MAX_BITS;

        for (int i = 0; i < MAX_BITS; ++i) give[i] = can_give + (extra > 0), -- extra;

        // for (auto &el : give) std::cout << el << " ";

        std::vector<int64_t> A(M, L);
        std::map<int64_t, std::vector<int>> loc;
        for (int64_t i = 0, x = 1, y = 1; i < MAX_BITS; ++i) {
                x = give[i];
                while (x --> 0) A.push_back(y);
                y *= 2;
        }

        assert((int) A.size() == N);

        for (int i = 0; i < N; ++i) loc[A[i]].push_back(i);

        for (auto &el : A) std::cout << el << " ";
        std::cout << std::endl;

        std::vector<int64_t> B(M);
        for (auto &el : B) std::cin >> el;

        std::vector<int> X(N);
        for (int i = 0; i < M; ++i) {
                X[loc[L].back()] = i;
                loc[L].pop_back();

                B[i] -= L;
                for (int64_t j = 0, x = 0, y = 1; j < MAX_BITS; ++j) {
                        if (B[i] % 2 <= (int) loc[y].size()) {
                                x = B[i] % 2;
                                while (x --> 0) X[loc[y].back()] = i, loc[y].pop_back();
                        }
                        B[i] /= 2;
                        y *= 2;
                }
        }

        for (auto &el : X) std::cout << el + 1 << " ";
        std::cout << std::endl;

        return 0;
}
