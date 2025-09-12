package com.github.kaushal_26.codeforces.`2141`.e

fun multiply(a: Long, b: Long): Long {
    val mod = 998244353
    return (a * b % mod)
}

fun add(a: Long, b: Long): Long {
    val mod = 998244353
    return (a + b) % mod
}

fun solve() {
    val s = readln()

    val countQ = s.count { it -> it == '?' }

    var powQ = 1L
    for (i in 0 until countQ) powQ = multiply(powQ, 2L)
    if (s[0] == '1') {
        println(powQ)
        return
    }

    var result = 0L
    for (i in s.length - 1 downTo 0) {
        if (s[i] == '0') {
            if (i != 0) {
                result = add(result, powQ)
            }
            break
        } else if (s[i] == '1') {
            // do nothing
        } else {
            powQ = multiply(powQ, 499122177L) // powQ /= 2
            result = add(result, powQ)
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
