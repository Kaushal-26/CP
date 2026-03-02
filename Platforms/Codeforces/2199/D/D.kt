package com.github.kaushal_26.codeforces.`2199`.d

fun solve() {
    val arrayLengths = readln().split(" ").map { it.toInt() }
    val n = arrayLengths[0]
    val m = arrayLengths[1]

    val a = readln().split(" ").map { it.toInt() }
    val b = readln().split(" ").map { it.toInt() }

    if (n == 1 && m == 1) {
        if (a[0] == b[0]) {
            println("YES")
        } else {
            println("NO")
        }
        return
    } else if (n == 1) {
        var found = false
        for (i in 1 until m - 1) {
            if (a[0] == b[i]) {
                found = true
                break
            }
        }
        if (found) {
            println("YES")
        } else {
            println("NO")
        }
        return
    } else if (m == 1) {
        var found = false
        for (i in 1 until n - 1) {
            if (b[0] == a[i]) {
                found = true
                break
            }
        }
        if (found) {
            println("YES")
        } else {
            println("NO")
        }
        return
    } else {
        val hA = HashSet<Int>()
        for (i in 1 until n - 1) hA.add(a[i])
        for (i in 1 until m - 1) {
            if (hA.contains(b[i])) {
                println("YES")
                return
            }
        }
        println("NO")
    }
}

fun main() {
    val testcases = readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}
