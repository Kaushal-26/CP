package com.github.kaushal_26.codeforces.`2142`.c

fun solve() {
    val s = readln()

    val lowerCaseDigits = ArrayList<Int>()
    val upperCaseDigits = ArrayList<Int>()

    for (i in s.indices) {
        if (s[i] == 'b') {
            if (lowerCaseDigits.isNotEmpty())
                lowerCaseDigits.removeLast()
        } else if (s[i] == 'B') {
            if (upperCaseDigits.isNotEmpty())
                upperCaseDigits.removeLast()
        } else {
            if (s[i].isLowerCase()) {
                lowerCaseDigits.add(i)
            } else {
                upperCaseDigits.add(i)
            }
        }
    }

    var indexes = lowerCaseDigits + upperCaseDigits
    indexes = indexes.sorted()

    val result = StringBuilder()
    for (index in indexes) {
        result.append(s[index])
    }

    println(result)
}

fun main() {
    val testcases = readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}
