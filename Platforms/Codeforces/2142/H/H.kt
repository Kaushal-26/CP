package com.github.kaushal_26.codeforces.`2142`.h

class FT(n: Int) {
    private val s = LongArray(n)

    fun update(posInput: Int, dif: Long) { // a[pos] += dif
        var pos = posInput
        while (pos < s.size) {
            s[pos] += dif
            pos = pos or (pos + 1)
        }
    }

    fun query(posInput: Int): Long { // sum of values in [0, pos)
        var pos = posInput
        var res = 0L
        while (pos > 0) {
            res += s[pos - 1]
            pos = pos and (pos - 1)
        }
        return res
    }
}


fun solve() {
    val (n, m, q) = readln().split(" ").map { it.toInt() }
    val grid = Array(n) { CharArray(m) }
    for (i in 0 until n) {
        val row = readln()
        for (j in 0 until m) {
            grid[i][j] = row[j]
        }
    }
    val queries = Array(q) { IntArray(2) }
    for (i in 0 until q) {
        val (x, y) = readln().split(" ").map { it.toInt() - 1 }
        queries[i][0] = x
        queries[i][1] = y
    }

    val fenwickTree = FT(n * m)

    var countIcons = 0
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (grid[i][j] == '*') {
                fenwickTree.update(i + j * n, 1)
                countIcons ++
            }
        }
    }

    for (i in 0 until q) {
        val (x, y) = queries[i]
        val pos = x + y * n
        if (grid[x][y] == '*') {
            grid[x][y] = '.'
            fenwickTree.update(pos, -1)
            countIcons --
        } else {
            grid[x][y] = '*'
            fenwickTree.update(pos, 1)
            countIcons ++
        }

        val iconsInFirstPart = fenwickTree.query(countIcons)
        val result = countIcons - iconsInFirstPart
        println(result)
    }
}

fun main() {
    val testcases = 1
    for (i in 0 until testcases) {
        solve()
    }
}
