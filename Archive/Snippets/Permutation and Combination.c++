const int N = 1e6 + 5;
mint fact[N], ifact[N];

void initial() {
        fact[0] = 1;
        for(int i = 1; i < N; ++i) fact[i] = fact[i - 1] * i;
        ifact[N - 1] = fact[N - 1].inv();
        for(int i = N - 2; i >= 0; --i) ifact[i] = ifact[i + 1] * (i + 1);
}

mint nPr(int n, int r) {
        if(n < r || n < 0) return 0;
        return fact[n] * ifact[n - r];
}

mint nCr(int n, int r) {
        if(n < r || n < 0) return 0;
        return fact[n] * ifact[r] * ifact[n - r];
}
