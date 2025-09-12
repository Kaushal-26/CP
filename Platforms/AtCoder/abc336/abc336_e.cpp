#include <bits/stdc++.h>

using namespace std;

#define overload(a, b, c, d, e, ...)    e
#define FORS(i, a, b, c)                for(int i = (a); i < (int)(b); i += c)
#define FOR1(i, a, b)                   for(int i = (a); i < (int)(b); ++i)
#define F0R(i, a)                       for(int i = (0); i < (int)(a); ++i)
#define ROFS(i, a, b, c)                for(int i = (b) - 1; i >= (int)(a); i -= c)
#define ROF1(i, a, b)                   for(int i = (b) - 1; i >= (int)(a); --i)
#define R0F(i, a)                       for(int i = (a) - 1; i >= (int)(0); --i)
#define FOR(...)                        overload(__VA_ARGS__, FORS, FOR1, F0R)(__VA_ARGS__)
#define ROF(...)                        overload(__VA_ARGS__, ROFS, ROF1, R0F)(__VA_ARGS__)
#define REP(i, x)			for(auto &i : x)

template <class T> auto V(const T& value, int size) {
        return vector<T>(size, value);
}

template <class T, class... D> auto V(const T& value, int size, D... w) {
        auto W = V(value, w...);
        return vector<decltype(W)>(size, W);
}

template <class T> bool ckmin(T &a, const T b) {
        return b < a ? a = b, 1 : 0;
}

template<class T> bool ckmax(T &a, const T b) {
        return b > a ? a = b, 1 : 0;
}

using LL 			        = long long;
using LLL                               = __int128_t;
using LD 			        = long double;

// const int mod 	                        = 1e9 + 7;
// const int MOD	                        = 998244353;
// const int N                             = 2e5 + 5;

// index, mod, sum, flag
LL dp[20][200][200][2];

int M, cur_mod;
LL N, answer;
string S;
LL pw[20];

LL rec(int id, int mod, int sum, int flag) {
        if(id == (int)S.size()) return (mod == 0 && sum == cur_mod);

        LL &ret = dp[id][mod][sum][flag];

        if(ret != -1) return ret;

        ret = 0;
        FOR(i, 0, flag ? (S[id] - '0' + 1) : 10) {
                ret += rec(id + 1, (mod + (i * pw[id]) % cur_mod) % cur_mod, sum + i, flag & (S[id] - '0' == i));
        }

        // cout << id << " " << mod << " " << sum << " " << flag << " " << cur_mod << " " << ret << endl;
        return ret;
}

int main() {
        cin.tie(0) -> sync_with_stdio(0);

        cin >> N;
        S = to_string(N);
        M = S.size();
        pw[M - 1] = 1;
        ROF(i, M - 1) pw[i] = pw[i + 1] * 10;
        
        FOR(i, 1, 200) {
                memset(dp, -1, sizeof dp);
                cur_mod = i;
                answer += rec(0, 0, 0, 1);
        }

        cout << answer;
        return 0;
}
