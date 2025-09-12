package com.github.kaushal_26.codeforces.`2142`.e

fun solve() {
    val n = readln().toInt()
    val arr = readln().split(" ").map { it.toInt() }

    val q = readln().toInt()
    val queries = mutableListOf<Pair<Int, Int>>()
    for (i in 0 until q) {
        val (l, r) = readln().split(" ").map { it.toInt() }
        queries.add(Pair(l - 1, r))
    }

    val prefixBitCount = Array(n) { IntArray(31) }
    for (i in arr.indices) {
        for (j in 0..30) {
            if (i > 0) {
                prefixBitCount[i][j] = prefixBitCount[i - 1][j]
            }
            if ((arr[i] and (1 shl j)) != 0) {
                prefixBitCount[i][j]++
            }
        }
    }

    for ((l, k) in queries) {
        var low = l
        var high = n - 1
        var ans = -1
        while (low <= high) {
            val mid = (low + high) / 2
            var canForm = 0
            for (j in 0..30) {
                val countInRange = prefixBitCount[mid][j] - if (l > 0) prefixBitCount[l - 1][j] else 0
                if (countInRange >= (mid - l + 1)) {
                    canForm = canForm or (1 shl j)
                }
            }
            if (canForm >= k) {
                ans = mid + 1
                low = mid + 1
            } else {
                high = mid - 1
            }
        }
        print("$ans ")
    }
    println()
}

fun main() {
    val testcases = readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}
