package com.github.kaushal_26.codeforces.`2142`.a

fun solve() {
    val n = readln().toInt()
    val arr = readln().split(" ").map { it.toInt() }

    val distinctElements = hashMapOf<Int, Int>()
    for (i in arr) {
        distinctElements[i] = distinctElements.getOrDefault(i, 0) + 1
    }

    for (k in distinctElements) {
        if (distinctElements[k.key] == 1) {
            for (i in arr.indices) {
                if (arr[i] == k.key) {
                    println(i + 1)
                    return
                }
            }
        }
    }
}

fun main() {
    val testcases = readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}
