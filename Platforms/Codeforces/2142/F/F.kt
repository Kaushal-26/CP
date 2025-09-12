package com.github.kaushal_26.codeforces.`2142`.f

fun check(n: Int, m: Int, a: Array<Array<Int>>, b: Array<Array<Int>>): Boolean {
    val minA = Array(n) { n * m + 1 }
    val ptrA = Array(n * m) { -1 }
    for (i in 0 until n) {
        for (j in 0 until m) {
            minA[i] = minOf(minA[i], a[i][j])
        }
        ptrA[minA[i]] = i
    }

    val minB = Array(n) { n * m + 1 }
    val ptrB = Array(n * m) { -1 }
    for (i in 0 until n) {
        for (j in 0 until m) {
            minB[i] = minOf(minB[i], b[i][j])
        }
        ptrB[minB[i]] = i
    }

    val checkRow = HashSet<Int>()
    for (i in 0 until n * m) {
        if (ptrA[i] == -1 && ptrB[i] == -1) continue

        if (ptrA[i] == -1 || ptrB[i] == -1) {
            return false
        }

        for (j in 0 until m) {
            checkRow.add(a[ptrA[i]][j])
        }
        for (j in 0 until m) {
            if (!checkRow.contains(b[ptrB[i]][j])) {
                return false
            }
            checkRow.remove(b[ptrB[i]][j])
        }
    }

    return true

}
fun solve() {
    val (n, m) = readln().split(" ").map { it.toInt() }
    val a = Array(n) { Array(m) { 0 } }
    val b = Array(n) { Array(m) { 0 } }
    for (i in 0 until n) {
        val row = readln().split(" ").map { it.toInt() }
        for (j in 0 until m) {
            a[i][j] = row[j] - 1
        }
    }
    for (i in 0 until n) {
        val row = readln().split(" ").map { it.toInt() }
        for (j in 0 until m) {
            b[i][j] = row[j] - 1
        }
    }

    if (!check(n, m, a, b)) {
        println("NO")
        return
    }

    val nA = Array(m) { Array(n) { 0 } }
    val nB = Array(m) { Array(n) { 0 } }
    for (i in 0 until n) {
        for (j in 0 until m) {
            nA[j][i] = a[i][j]
            nB[j][i] = b[i][j]
        }
    }

    if (!check(m, n, nA, nB)) {
        println("NO")
        return
    }

    println("YES")
}

fun main() {
    val testcases = readln().toInt()
    for (i in 0 until testcases) {
        solve()
    }
}
