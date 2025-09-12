package com.github.kaushal_26.codeforces.`2142`.d

fun solve() {
    val n = readln().toInt()

    val frequency = Array(26) { 0 }
    for (char in readln()) {
        frequency[char - 'a']++
    }

    frequency.sortDescending()

    if (2 * frequency[0] > n) {
        println(2 * frequency[0] - n)
    } else {
        println(n % 2)
    }
}

fun main() {
    val testcases = readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}
