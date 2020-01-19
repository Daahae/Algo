/* 조이스틱
 * 90.9 / 100
 * 2020.01.19
 */
class Solution {
    fun solution(name: String): Int {
        var target = name[0] - 'A'
        var answer = when {
            target <= 13 ->  target
            else -> 26 - target
        }

        var aCnt = 0
        var leftSum = 0
        for (i in 1 until name.length) {
            target = name[i] - 'A'
            aCnt = when {
                target == 0 -> aCnt +  1
                else -> {
                    leftSum += aCnt + 1 + when {
                        target <= 13 ->  target
                        else -> 26 - target
                    }
                    0
                }
            }
        }

        aCnt = 0
        var rightSum = 0
        for (i in (name.length-1).downTo(1)) {
            target = name[i] - 'A'
            aCnt = when {
                target == 0 -> aCnt +  1
                else -> {
                    rightSum += aCnt + 1 + when {
                        target <= 13 ->  target
                        else -> 26 - target
                    }
                    0
                }
            }
        }
        answer += when {
            leftSum >= rightSum -> rightSum
            else -> leftSum
        }
        return answer
    }
}