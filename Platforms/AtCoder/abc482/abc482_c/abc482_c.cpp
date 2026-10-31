#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T, typename compare = std::less<T>>
using ordered_set = tree<T, null_type, compare, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
        #ifdef Kaushal_26
        auto start_time = std::chrono::high_resolution_clock::now();
        #endif

        auto solve = [&]() -> void {
                int H, W, C, Q; std::cin >> H >> W >> C >> Q;

                std::map<long long, int> A_counter, B_counter;
                ordered_set<long long> A, B;
                for (int i = 0; i < C; ++i) {
                        long long r, c; std::cin >> r >> c;
                        A.insert(r * C + A_counter[r * C]);
                        B.insert(c * C + B_counter[c * C]);
                        A_counter[r * C]++, B_counter[c * C]++;
                }

                for (int r = 0; r < Q; ++r) {
                        long long t, a, b; std::cin >> t >> a >> b;
                        if (t == 1) {
                                std::cout << A.order_of_key(b * C + C) - A.order_of_key(a * C) << "\n";
                        } else {
                                std::cout << B.order_of_key(b * C + C) - B.order_of_key(a * C) << "\n";
                        }
                }
        };

        int testcases = 1; //std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                #ifdef Kaushal_26
                std::cout << "\n\n" << std::string(50, '=');
                std::cout << "\n\n" << "Testcase #" << i << ": ";
                #endif

                solve();
        }

        #ifdef Kaushal_26
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        std::cout << "\n\n" << std::string(50, '=');
        std::cout << "\n\n" << "Time taken: " << duration.count() << " milliseconds";
        std::cout << "\n\n" << std::string(50, '=') << "\n\n";
        #endif

        return 0;
}