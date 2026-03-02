package com.github.kaushal_26.codeforces.`2199`.e

import kotlin.math.abs

fun count(a: Long, b: Long): Long {
    if (a < b) {
        return b - a
    } else if (a > b) {
        return a - b
    }
    return 2
}

fun solve() {
    val arrayLengths = readln().split(" ").map { it.toInt() }
    val n = arrayLengths[0]
    val q = arrayLengths[1]

    val a = readln().split(" ").map { it.toInt() }.toMutableList()
    val queries = readln().split(" ").map { it.toLong() }.toLongArray()

    val indexSortedQueries = queries.withIndex().sortedBy { it.value }.map { it.index }

    a.add(a[n - 1] + 1)

    val answer = Array(q) { -1L }
    var j = 0
    var gone = 0L
    for (i in 1 until n + 1) {
        while (j < q && gone + count(a[i].toLong(), a[i - 1].toLong()) >= queries[indexSortedQueries[j]]) {
            if (a[i] > a[i - 1]) {
                answer[indexSortedQueries[j]] = a[i - 1] + (queries[indexSortedQueries[j]] - gone - 1)
            } else if (a[i] < a[i - 1]) {
                answer[indexSortedQueries[j]] = a[i - 1] - (queries[indexSortedQueries[j]] - gone - 1)
            } else {
                if (queries[indexSortedQueries[j]] - gone == 1L) {
                    answer[indexSortedQueries[j]] = a[i - 1].toLong()
                } else {
                    answer[indexSortedQueries[j]] = 0
                }
            }
           j++
        }
        gone += count(a[i].toLong(), a[i - 1].toLong())
    }

    for (i in 0 until q) {
        print("${answer[i]} ")
    }
    println()
}

fun main() {
    val testcases = 1 // readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}
