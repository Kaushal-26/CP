#include <bits/stdc++.h>

int N;
const int _N = 200500;
std::vector<int> T[_N];
int C[_N], F[_N], P[_N];

int bfs(int src) {
        std::queue<int> Q;

        for (int i = 0; i < N; ++i) F[i] = P[i] = -1;

        F[src] = 0, Q.push(src);
        while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(auto v: T[cur]) {
                        if(F[v] == -1) {
                                F[v] = F[cur] + 1;
                                P[v] = cur;
                                Q.push(v);
                        }
                }
        }
        for (int i = 0; i < N; ++i) if (F[i] > F[src]) src = i;
        return src;
}

std::vector<int> go(int node, int parent, int distance) {
        std::vector<int> colors;

        std::queue<std::array<int, 3>> Q;
        Q.push({node, parent, 0});

        while (!Q.empty()) {
                auto [u, v, current_distance] = Q.front(); Q.pop();

                if (current_distance == distance) {
                        colors.push_back(C[u]);
                        continue;
                }

                for (auto s : T[u]) {
                        if (s == v) continue;
                        Q.push({s, u, current_distance + 1});
                }
        }

        return colors;
}

int main() {
        #ifdef Kaushal_26
        auto start_time = std::chrono::high_resolution_clock::now();
        #endif

        auto solve = [&]() -> void {
                std::cin >> N;
                for (int i = 0, u, v; i < N - 1; ++i) {
                        std::cin >> u >> v; --u, --v;
                        T[u].push_back(v);
                        T[v].push_back(u);
                }
                for (int i = 0; i < N; ++i) std::cin >> C[i], -- C[i];

                auto s = bfs(0);
                auto g = bfs(s);

                std::vector<int> path;
                for (int nxt = g; nxt != -1; nxt = P[nxt]) {
                        path.push_back(nxt);
                }
                std::ranges::reverse(path);

                int diameter = static_cast<int>(path.size()) - 1;
                int radius = diameter / 2;

                long long answer = 0;

                if (diameter % 2 == 0) {
                        int centre = path[radius];

                        std::vector<int> done(N);
                        for (auto &s : T[centre]) {
                                auto colors_at_r = go(s, centre, radius - 1);

                                for (auto &c : colors_at_r) {
                                        answer += done[c];
                                }
                                for (auto &c : colors_at_r) {
                                        done[c] ++;
                                }
                        }
                } else {
                        int centre_1 = path[radius];
                        int centre_2 = path[radius + 1];

                        auto colors_at_c1 = go(centre_1, centre_2, radius);
                        auto colors_at_c2 = go(centre_2, centre_1, radius);

                        std::vector<int> done_1(N), done_2(N);
                        for (auto &c : colors_at_c1) done_1[c]++;
                        for (auto &c : colors_at_c2) done_2[c]++;

                        for (int i = 0; i < N; ++i) {
                                answer += (long long)done_1[i] * done_2[i];
                        }
                }

                std::cout << answer << "\n";
        };

        int testcases = 1; // std::cin >> testcases;
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