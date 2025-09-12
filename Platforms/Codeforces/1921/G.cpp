#include <bits/stdc++.h>

using namespace std;

#define pb                      	push_back
#define nl				"\n"
#define sp 				" "
#define all(x)                  	(x).begin(), (x).end()
#define sz(x)				(int)(x).size()
#define deci(x)			        fixed << setprecision(x)
#define set(a, x)			memset(a, x, sizeof a)
#define dedup(a)			a.erase(unique(all(a)), a.end())

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

        };

        int testcases = 1; cin >> testcases;
        FOR(testcase_number, testcases) solo_leveling(testcase_number);
        return 0;
}
