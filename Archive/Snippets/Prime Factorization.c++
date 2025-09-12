vector<int> p, spf;
void init() {
        spf.resize(N);
        for(int i = 2; i < N; i++) {
                if(spf[i] == 0) spf[i] = i, p.push_back(i);
                for(int j = 0; j < (int)p.size() && i * p[j] < N; j++) spf[i * p[j]] = p[j];
        }
}

auto prime_factorisation(int x) {
        vector<array<int, 2>> prime_factors;
        while(x > 1) {
                int cnt = 0, Lp = spf[x];
                while(spf[x] == Lp) cnt++, x /= Lp;
                prime_factors.push_back({Lp, cnt});
        }
        return prime_factors;
}