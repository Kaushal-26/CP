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

const int mod 	                        = 1e9 + 7;
const int MOD	                        = 998244353;
const int N                             = 2e5 + 5;

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);

        auto solo_leveling = [&](int testcase_number) -> void {
                LL n; cin >> n;

                LL dp[19];
                dp[0] = 1;
                FOR(i, 1, 19) dp[i] = 5 * dp[i - 1];

                int i = 0;
                FOR(j, 19) if(dp[j] >= n) {
                        i = j;
                        break;
                }

                LL pw[19];
                pw[0] = pw[1] = 1;
                FOR(i, 2, 19) pw[i] = 10 * pw[i - 1];

                // FOR(i, 19) cout << i << " " << pw[i] << " " << dp[i] << "\n";

                // cout << i << '\n';
                LL ans = 0;
                while(i > 0) {
                        LL ok = 0;
                        FOR(j, 0, 9, 2) {
                                if(dp[i - 1] < n) {
                                        n -= dp[i - 1];
                                } else {
                                        ok = j;
                                        break;
                                }
                        }
                        // cout << i << " " << ok << " " << n << '\n';
                        ans += pw[i] * ok;
                        i--;
                }

                cout << ans << '\n';
        };

        int testcases = 1; // cin >> testcases;
        FOR(testcase_number, testcases) {
                solo_leveling(testcase_number);
        }
        return 0;
}
