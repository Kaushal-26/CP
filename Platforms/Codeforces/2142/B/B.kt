package com.github.kaushal_26.codeforces.`2142`.b

fun solve() {
    val k = readln().toInt()
    var count = 0
    for (i in 1..1000*k) {
        if (i % 3 == 0 || i % 10 == 3) continue
        ++ count
        if (count == k) {
            println(i)
            return
        }
    }
}

fun main() {
    val testcases = readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}