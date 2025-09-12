package com.github.kaushal_26.codeforces.`2141`.a

fun solve() {
    val n = readln().toInt()
    val arr = readln().split(" ").map { it.toInt() }

    val result = ArrayList<Int>()
    var min = arr[0]
    for (i in 1 until n) {
        if (arr[i] >= min) {
            result.add(i + 1)
        } else {
            min = arr[i]
        }
    }

    println(result.size)
    for (index in result) {
        print("$index ")
    }
    println()
}

fun main() {
    val testcases = readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}
