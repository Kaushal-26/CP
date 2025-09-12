package com.github.kaushal_26.codeforces.`2141`.d

import kotlin.math.max

fun solve() {
    val (n, m) = readln().split(" ").map { it.toLong() }
    val a = readln().split(" ").map { it.toLong() }.sorted()

    var req = 0L
    var max = a[n.toInt() - 1]
    for (i in 0 until n.toInt()) {
        req += max - a[i]
    }

    if (req > m) {
        println("-1")
        return
    }

    val extra = (m - req) / n
    max += extra

    var result = 0L
    for (i in 1..<n) {
        result += if (a[i.toInt()] == a[0]) {
            max(0L, max - a[i.toInt()] - 1)
        } else {
            max - a[i.toInt()]
        }
    }

    println(result)
}

fun main() {
    val testcases = readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}
