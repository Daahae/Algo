package programmers;

import java.util.Arrays;
import java.util.Comparator;

/**
 * @{link} 	https://programmers.co.kr/learn/courses/30/lessons/42746
 * @date   	2020-05-06
 * @author 	rkddlsgur983
 */
public class PRO_L2_가장큰수 {
	public String solution(int[] numbers) {
		int len = numbers.length;
		String[] num = new String[len];
		for (int i = 0; i < len; ++i) {
			num[i] = String.valueOf(numbers[i]);
		}
		Arrays.sort(num, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				int l1 = o1.length();
				int l2 = o2.length();
				String s1 = o1;
				String s2 = o2;
				for (int i = l1; i < 12; i+=l1) {
					s1 += o1;
				}
				for (int i = l2; i < 12; i+=l2) {
					s2 += o2;
				}
				return s2.compareTo(s1);
			}
		});
        String answer = "";
        for (int i = 0; i < len; ++i) {
        	answer += num[i];
        }
        if (answer.charAt(0) == '0') {
            answer = String.valueOf(Long.parseLong(answer));
        }
        return answer;
    }
}
