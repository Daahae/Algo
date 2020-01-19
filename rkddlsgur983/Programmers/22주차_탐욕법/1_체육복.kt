/* 체육복
 * 2020.01.19
 */
class Solution {
    fun solution(n: Int, lost: IntArray, reserve: IntArray): Int {

        for (r in reserve) {
            if (lost.contains(r)) {
                lost[lost.indexOf(r)] = -1
                reserve[reserve.indexOf(r)] = -1
            }
        }

        var answer = 0
        for (i in 1..n) {
            when (lost.contains(i)) {
                true -> {
                    if (i > 1 && reserve.contains(i-1)) {
                        reserve[reserve.indexOf(i-1)] = -1
                        answer += 1
                    } else if (i < n && reserve.contains(i+1)) {
                        reserve[reserve.indexOf(i+1)] = -1
                        answer += 1
                    }
                }
                false -> answer += 1
            }
        }
        return answer
    }
}