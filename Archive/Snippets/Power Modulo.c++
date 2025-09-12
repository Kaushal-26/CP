int power_mod(int v, int n, int mod = M) {
        v %= mod;
        if(v == 0) return 0;
        n %= (mod - 1); // if and only if mod is prime.
        int ret = 1;
        for(; n; n >>= 1, v = (v * v) % mod) if(n & 1) ret = (ret * v) % mod;
        return ret;
}