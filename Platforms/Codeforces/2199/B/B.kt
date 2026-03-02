package com.github.kaushal_26.codeforces.`2199`.b

fun solve() {
    var g = readln().split(" ").map { it.toInt() }.toMutableList()

    if (g[2] > g[3]) {
        g[3] = g[2].also { g[2] = g[3] }
        g[1] = g[0].also { g[0] = g[1] }
    }

    var res = 0
    if (g[0] < g[1]) {
        if (g[2] < g[1]) {
            res += g[2] - g[0]
            res += g[3] - g[1]
        } else {
            res += g[1] - g[0]
            res += g[2] - g[1]
            res += g[3] - g[2]
        }
    } else {
        res += g[0] - g[1]
        res += g[2] - g[0]
        res += g[3] - g[2]
    }

    println(res)
}

fun main() {
    val testcases = readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}
