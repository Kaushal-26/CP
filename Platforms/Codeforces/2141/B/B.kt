package com.github.kaushal_26.codeforces.`2141`.b

fun solve() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val a = readln().split(" ").map { it.toInt() }
    val b = readln().split(" ").map { it.toInt() }.toMutableList()

    val hA = HashSet<Int>()
    val hB = HashSet<Int>()
    for (i in a) hA.add(i)
    for (i in b) hB.add(i)

    var cA = 0
    var cB = 0
    for (i in 0 until n) if (!hB.contains(a[i])) cA++
    for (i in 0 until m) if (!hA.contains(b[i])) cB++

    if (cB >= cA) {
        println(2 * cA + 1)
    } else {
        println(2 * cB + 2)
    }
}

fun main() {
    val testcases = readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}
