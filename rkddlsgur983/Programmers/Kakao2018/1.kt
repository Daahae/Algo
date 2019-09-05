// 1. 오픈채팅방
class Solution {
    fun solution(record: Array<String>): Array<String> {

        val events = mutableMapOf<String, String>()
        for (r in record) {
            val s = r.split(" ".toRegex());
            when (s[0]) {
                "Enter", "Change" -> {
                    events[s[1]] = s[2]
                }
            }
        }

        val answer = mutableListOf<String>()
        for (r in record) {
            val s = r.split(" ".toRegex());
            when (s[0]) {
                "Enter" -> {
                    answer.add(events[s[1]] + "님이 들어왔습니다.")
                }
                "Leave" -> {
                    answer.add(events[s[1]] + "님이 나갔습니다.")
                }
            }
        }

        return answer.toTypedArray()
    }
}