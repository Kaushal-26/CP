#include <bits/stdc++.h>

int main() {
        std::cin.tie(0) -> sync_with_stdio(0);
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N, rK, cK, rD, cD; std::cin >> N >> rK >> cK >> rD >> cD;

                int r = std::abs(rK - rD), c = std::abs(cK - cD);
                int dis = std::max(r, c);

                if (rD + 1 == rK) {
                        std::cout << N - rK + 1 << "\n";
                } else if (rD - 1 == rK) {
                        std::cout << rK + 1 << "\n";
                } else if (cD + 1 == cK) {
                        std::cout << N - cK + 1 << "\n";
                } else if (cD - 1 == cK) {
                        std::cout << cK + 1 << "\n";
                } else if (rK >= rD && cK >= cD) {
                        int A = N - rK, B = N - cK;
                        if (B > A) std::swap(A, B);
                        std::cout << A + std::min(B, dis) << "\n";
                } else if (rK >= rD) {
                        int A = N - rK, B = cK;
                        if (B > A) std::swap(A, B);
                        std::cout << A + std::min(B, dis) << "\n";
                } else if (cK >= cD) {
                        int A = rK, B = N - cK;
                        if (B > A) std::swap(A, B);
                        std::cout << A + std::min(B, dis) << "\n";
                } else {
                        int A = rK, B = cK;
                        if (B > A) std::swap(A, B);
                        std::cout << A + std::min(B, dis) << "\n";
                }
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
