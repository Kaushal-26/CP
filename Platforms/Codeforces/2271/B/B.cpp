#include <bits/stdc++.h>

int main() {
        #ifdef Kaushal_26
        auto start_time = std::chrono::high_resolution_clock::now();
        #endif

        auto solve = [&]() -> void {
                int N, K; std::cin >> N >> K;

                int a[N];
                int cnt[N + 1] = {0};
                for (int i = 0; i < N; ++ i) {
                        std::cin >> a[i];
                        cnt[a[i]] ++;
                }

                int alice = 0, bob = 0;
                int alice_mex = 0, bob_mex = 0;
                for (int rep = 0; rep < N; ++ rep) {
                        // std::cout << rep << " " << alice_mex << " " << bob_mex << "\n";
                        if (rep % 2 == 0) {
                                if (cnt[alice_mex] > 0) {
                                        alice ++;
                                        -- cnt[alice_mex];
                                        if (alice == K) {
                                                alice_mex++;
                                                alice = 0;
                                        }
                                } else {
                                        break;
                                }
                        } else {
                                if (cnt[bob_mex] > 0) {
                                        bob ++;
                                        -- cnt[bob_mex];
                                        if (bob == K) {
                                                bob_mex++;
                                                bob = 0;
                                        }
                                } else {
                                        break;
                                }
                        }
                }

                std::cout << (alice_mex == bob_mex ? "NO" : "YES") << "\n";
        };

        int testcases = 1; std::cin >> testcases;
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