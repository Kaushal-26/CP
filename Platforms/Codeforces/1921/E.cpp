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

template <class T> bool ckmin(T &a, T b) {
        return b < a ? a = b, 1 : 0;
}
template<class T> bool ckmax(T &a, T b) {
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

        auto solo_leveling = [&](int testcase_number) -> int {
                int H, W; cin >> H >> W;

                auto a = V<int>(0, 2, 2);
                FOR(i, 2) FOR(j, 2) cin >> a[i][j];

                if(a[0][0] >= a[1][0]) return 2;

                int f = (a[1][0] - a[0][0]) % 2;
                int g = !f;

                int mv = (a[1][0] - a[0][0]) / 2;
                int vm = (a[1][0] - a[0][0] + 1) / 2;

                if(a[f][1] < a[g][1]) {
                        ckmin(vm, a[g][1] - 1);
                        ckmin(mv, a[f][1] - 1);

                        a[g][1] -= vm;
                        a[f][1] -= mv;

                        if(!g) a[g][0] += vm;
                        else a[g][0] -= vm;
                        if(!f) a[f][0] += mv;
                        else a[f][0] -= mv;

                        if(a[f][1] >= a[g][1]) {
                                if(!g) {
                                        if(a[f][0] >= a[g][0]) return g;
                                } else {
                                        if(a[f][0] <= a[g][0]) return g;
                                }
                        }
                } else {
                        ckmin(vm, W - a[g][1]);
                        ckmin(mv, W - a[f][1]);

                        a[g][1] += vm;
                        a[f][1] += mv;

                        if(!g) a[g][0] += vm;
                        else a[g][0] -= vm;
                        if(!f) a[f][0] += mv;
                        else a[f][0] -= mv;

                        if(a[f][1] <= a[g][1]) {
                                if(!g) {
                                        if(a[f][0] >= a[g][0]) return g;
                                } else {
                                        if(a[f][0] <= a[g][0]) return g;
                                }
                        }
                }

                return 2;
        };

        int testcases = 1; cin >> testcases;
        FOR(testcase_number, testcases) {
                int ok = solo_leveling(testcase_number);
                if(!ok) {
                        cout << "Alice";
                } else if(ok == 1) {
                        cout << "Bob";
                } else {
                        cout << "Draw";
                }
                cout << nl;
        }
        return 0;
}
