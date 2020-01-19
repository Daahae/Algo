/* 구명보트
 * 2020.01.19
 */
package Algorithm.Programmers.코팅테스트_연습.탐욕법;

import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int solution(int[] people, int limit) {

        // 내림차순
        Integer[] peopleArray = Arrays.stream(people).boxed().toArray(Integer[]::new);
        Arrays.sort(peopleArray, Comparator.reverseOrder());

        int answer = 0;
        int last = peopleArray.length-1;
        for (int person: peopleArray) {
            if (person == 0)
                continue;
            // 무게가 큰 사람과 작은 사람의 합이 limit이내인 경우
            if (person < limit && person + peopleArray[last] <= limit){
                peopleArray[last] = 0;
                last -= 1;
            }
            answer += 1;
        }
        return answer;
    }
}