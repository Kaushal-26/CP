package com.github.kaushal_26.codeforces.`2141`.c

fun solve() {
    val n = readln().toInt()

    val result = ArrayList<String>()
    var start = 0
    var end = n - 1
    while (start <= end) {
        for (i in start..end) {
            result.add("pushback a[$i]")
            result.add("min")
        }
        for (i in start..end) {
            result.add("popfront")
            if (i != end) result.add("min")
        }
        start ++
        end --
    }

    assert(result.size <= n * (n + 2))

    println(result.size)
    for (res in result) {
        println(res)
    }
}

fun main() {
    val testcases = 1
    for (i in 0 until testcases) {
        solve()
    }
}
