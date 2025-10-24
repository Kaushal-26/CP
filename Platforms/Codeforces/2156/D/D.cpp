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
        std::cin.exceptions(std::ios::badbit | std::ios::failbit);

        auto solve = [&]() -> void {
                int N; std::cin >> N;

                std::vector<int> cur;
                for (int i = 1; i < N; ++i) cur.push_back(i);

                std::vector<int> pos;
                for (int i = 1; i <= N; ++i) pos.push_back(i); 

                int x = 1;
                while((int) pos.size() > 1) {
                        std::vector<int> o, e;
                        for (int i = 0; i < (int) cur.size(); ++i) {
                                std::cout << "? " << cur[i] << " " << x << std::endl;

                                int b; std::cin >> b;
                                if (b) {
                                        o.push_back(cur[i]);
                                } else {
                                        e.push_back(cur[i]);
                                }
                        }

                        std::vector<int> oc, ec;
                        for (int i = 0; i < (int) pos.size(); ++i) {
                                if (pos[i] & x) oc.push_back(pos[i]);
                                else ec.push_back(pos[i]);
                        }

                        if (oc.size() != o.size()) {
                                cur = o;
                                pos = oc;
                        } else {
                                cur = e;
                                pos = ec;
                        }

                        x *= 2;
                }

                std::cout << "! " << pos[0] << std::endl;
        };

        int testcases = 1; std::cin >> testcases;
        for (int i = 1; i <= testcases; ++ i) {
                solve();
        }

        return 0;
}
