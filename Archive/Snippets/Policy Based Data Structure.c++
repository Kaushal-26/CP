#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

template<typename T, typename compare = less<T>>
using oset      = tree<T, null_type, compare, rb_tree_tag, tree_order_statistics_node_update>;