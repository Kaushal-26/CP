package com.github.kaushal_26.codeforces.`2199`.c

fun solve() {
    var n = readln().toInt()

    if (n == 1) {
        println("YES\n1\n*\n.")
        return
    }

    if (n % 5 == 0) {
        println("YES")
        println(n * 3 / 5)
        for (i in 0 until n / 5) {
            print(".*.")
        }
        println()
        for (i in 0 until n / 5) {
            print("...")
        }
        println()
    } else {
        n -= 3
        if (n % 5 == 0) {
            println("YES")
            println(n * 3 / 5 + 2)
            print("*.")
            for (i in 0 until n / 5) {
                print(".*.")
            }
            println()
            print("..")
            for (i in 0 until n / 5) {
                print("...")
            }
            println()
        } else {
            n -= 3
            if (n % 5 == 0) {
                println("YES")
                println(n * 3 / 5 + 4)
                print("*.")
                for (i in 0 until n / 5) {
                    print(".*.")
                }
                println(".*")
                print("..")
                for (i in 0 until n / 5) {
                    print("...")
                }
                println("..")
            } else {
                println("NO")
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
