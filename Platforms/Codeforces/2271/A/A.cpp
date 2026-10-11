#include <bits/stdc++.h>

int pos[2000][2000];

bool good(int x, int y) {
        return x >= 0 && x < 2000 && y >= 0 && y < 2000 && pos[x][y] == -1;
}

void go() {
        std::vector<std::array<int, 2>> points;
        points.push_back({0, 0});

        for (int rep = 0; rep <= 2000; ++ rep) {
                std::vector<std::array<int, 2>> new_points;
                for (auto [x, y] : points) {
                        if (good(x, y)) pos[x][y] = rep;
                        if (good(x, y + 1)) pos[x][y + 1] = rep + 1;
                        if (good(x, y - 1)) pos[x][y - 1] = rep + 1;
                        new_points.push_back({x + 1, y + 1});
                        new_points.push_back({x + 1, y - 1});
                }
                std::swap(points, new_points);
                std::ranges::sort(points);
                points.erase(std::unique(points.begin(), points.end()), points.end());
        }
}

int main() {
        #ifdef Kaushal_26
        auto start_time = std::chrono::high_resolution_clock::now();
        #endif

        auto solve = [&]() -> void {
                int X, Y; std::cin >> X >> Y;
                std::cout << pos[X][Y] << "\n";
        };

        memset(pos, -1, sizeof(pos));
        go();

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