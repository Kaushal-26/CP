package lib.atcoder

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

    fun lowerBound(sumInput: Long): Int? { // min pos s.t. sum of [0, pos] >= sum
        if (sumInput <= 0) return null
        var sum = sumInput
        var pos = 0
        var pw = 1 shl 25
        while (pw > 0) {
            if (pos + pw <= s.size && s[pos + pw - 1] < sum) {
                sum -= s[pos + pw - 1]
                pos += pw
            }
            pw = pw shr 1
        }
        return if (pos < s.size) pos else null
    }
}
