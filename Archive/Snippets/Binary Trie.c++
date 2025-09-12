struct Trie {
        const int nodes = 2;
        const int log = 20;

        vector<vector<int>> next;
        vector<int> cnt;
        int root, cur;

        void clear() {
                next.clear();
                cnt.clear();
                add();
                root = 0, cur = 1;
        }

        void add() {
                next.push_back({});
                for (int j = 0; j < nodes; j++) next.back().push_back(-1);
                cnt.push_back(0);
        }
        
        Trie() {
                add();
                root = 0, cur = 1;
        }

        void insert(int value) {
                int go = root;
                ++cnt[go];
                for (int i = log - 1; i >= 0; --i) {
                        int bit = value >> i & 1;
                        if(next[go][bit] == -1) {
                                next[go][bit] = cur++;
                                add();
                        }
                        go = next[go][bit];
                        ++cnt[go];
                }
        }

        void erase(int value) {
                int go = root;
                --cnt[go];
                for (int i = log - 1; i >= 0; --i) {
                        go = next[go][value >> i & 1];
                        --cnt[go];
                }
        }

        bool search(int value) {
                int go = root;
                for (int i = log - 1; i >= 0; --i) {
                        if(next[go][value >> i & 1] == -1 || cnt[next[go][value >> i & 1]] == 0) return 0;
                        go = next[go][value >> i & 1];
                }
                return 1;
        }

        int query_maximum(int value) {
                int go = root;
                int rt = 0;
                for (int i = log - 1; i >= 0; --i) {
                        int bit = value >> i & 1;
                        if(next[go][bit ^ 1] != -1 && cnt[next[go][bit ^ 1]] > 0) {
                                rt |= 1LL << i;
                                go = next[go][bit ^ 1];
                        } else {
                                go = next[go][bit];
                        }
                }
                return rt;
        }

        int query_minimum(int value) {
                int go = root;
                int rt = 0;
                for (int i = log - 1; i >= 0; --i) {
                        int bit = value >> i & 1;
                        if(next[go][bit] != -1 && cnt[next[go][bit]] > 0) {
                                go = next[go][bit];
                        } else {
                                go = next[go][bit ^ 1];
                                rt |= 1LL << i;
                        }
                }
                return rt;
        }
};