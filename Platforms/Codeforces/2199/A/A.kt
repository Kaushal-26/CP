package com.github.kaushal_26.codeforces.`2199`.a

fun solve() {
    val k = readln().toInt();
    val a = readln().split(" ").map { it.toInt() }
    val b = readln().split(" ").map { it.toInt() }

    val alice = a[0] + b[0];
    val bob = a[1] + b[1] + k;

    if (alice > bob) {
        println("NO");
    } else if (alice == bob) {
        if (a[0] < a[1] || b[0] < b[1]) {
            println("YES")
        } else {
            println("NO")
        }
    } else {
        println("YES")
    }
}

fun main() {
    val testcases = readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}
