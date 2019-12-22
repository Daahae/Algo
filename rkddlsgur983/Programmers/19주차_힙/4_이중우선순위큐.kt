/* 이중우선순위큐
 * 2019.12.17
 */
import java.util.*

class Solution {
    fun solution(operations: Array<String>): IntArray {
        val ascendingPQ = PriorityQueue<Int>(Collections.reverseOrder())
        val descendingPQ = PriorityQueue<Int>()

        for (o in operations) {
            val op = o.split(" ")
            when (op[0]) {
                "I" -> {
                    ascendingPQ.add(op[1].toInt())
                    descendingPQ.add(op[1].toInt())
                }
                "D" -> {
                    if (!ascendingPQ.isEmpty()) {
                        when (op[1].toInt()) {
                            1 -> {
                                val max = ascendingPQ.poll()
                                descendingPQ.remove(max)
                            }
                            -1 -> {
                                val min = descendingPQ.poll()
                                ascendingPQ.remove(min)
                            }
                        }
                    }
                }
            }
        }
        return when (!ascendingPQ.isEmpty()) {
            true -> intArrayOf(ascendingPQ.peek(), descendingPQ.peek())
            false -> intArrayOf(0, 0)
        }
    }
}